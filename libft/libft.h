/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:40:24 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/10 13:53:56 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

/* Structs definition */

typedef struct s_gnlmfers
{
	char		*chunk;
	char		*line;
	char		*totrim;
	char		*nl;
	char		buffer[BUFFER_SIZE +1];
}	t_fd;

/* libc */
int		tablen(char **tab);
int		ft_isalpha(int c);
int		ft_isdigit2(char *str);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/* additionals */
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim2(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	**ft_split_ws(char const *s, char c);
char	**ft_split_coma(char const *s, char c);

/* printf */

int		ft_printf(const char *format, ...);
int		ft_print_x(unsigned long nbr, const char *format);
int		ft_print_s(char *str);
int		ft_print_p(void *p);
int		ft_print_i(long nbr);
int		ft_print_c(char c);

/* GNL */

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strndup(const char *src, size_t n);
char	*gnl_strdup(const char *s1);

#endif