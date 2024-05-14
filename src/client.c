/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:45:38 by jarunota          #+#    #+#             */
/*   Updated: 2024/05/14 18:10:51 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Sends a signal to a process with the given pid, representing a character.
 * The character is sent bit by bit, 
 		SIGUSR1 representing 1 and SIGUSR2 representing 0.
 * The process ID of the process to send the signal to.
*/

#include "../include/minitalk.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		handle_errors("./client <pid> <message>\n");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("Invalid PID");
	if (*argv[2] == 0)
		handle_errors("Invalid message (empty)");
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		write(1, "Character has been sucessfully receieved!\n", 42);
}

int	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
	return (0);
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	pid_t		sv_pid;
	char		*msg;

	msg = ft_strjoin(argv[2], "\n");
	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	ft_printf("_________________________________________\n\n");
	ft_printf("          client PID : %d\n", getpid());
	ft_printf("_________________________________________\n\n");
	config_signals();
	while (send_msg(sv_pid, msg))
		pause();
	write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
