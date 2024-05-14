/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:05:23 by jarunota          #+#    #+#             */
/*   Updated: 2024/05/14 18:02:27 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// Signal handler function for handling SIGUSR1 and SIGUSR2 signals
// If the signal is SIGUSR1, set the corresponding bit in current_char
// If the bit index reaches 8, print the current character and reset 
// the bit index and current_char

/**
 * 		Checks if the signal is SIGUSR1. If it is, it will
 * assign 1 to the LSB. Else, it will assign 0 (actually it simply
 * won't modify it).
 *
 * Example:
 * 00101100   current_char
 * 00000001   result of (sigsent == SIGUSR1)
 * --------
 * 00101101   result stored in message after the bitwise OR operation
 *
 * It will then increment the bit index.
 * If it is 8, it means that
 * the char has been fully transmitted. It will then print it and
 * reset the bit index and the current char.
 * Else, it will shift the current char to the left by 1
 */

/*
void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	current_char;
	static int				bit_index;
	int						client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		current_char |= (1 << (7 - bit_index));
	bit_index++;
	kill(client_pid, SIGUSR1);
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
}
*/

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
}

// 1 -> 00000001
// a -> 01100001

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("_________________________________________\n\n");
	ft_printf("          server PID : %d\n", pid);
	ft_printf("_________________________________________\n\n");
	while (1)
		config_signals();
	return (EXIT_SUCCESS);
}
