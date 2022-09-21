/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:13:45 by clesaffr          #+#    #+#             */
/*   Updated: 2022/09/04 22:55:00 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

void			*ft_bzero(void *src, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memset(void *src, int x, size_t n);
int				ft_size_of_doubletab(char **tab);
void			ft_free_doubletab(char **doubletab);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(char c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
int				ft_strlcpy(char *dest, const char *src, unsigned int n);
char			*ft_strnchr(const char *p, int i, int chr);
char			*ft_strrchr(const char *p, int chr);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strnstr(char *str, char *to_find, int len);
char			*ft_strupcase(char *str);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strjoin(const char *s1, const char *s2);
char			**ft_split(const char *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putstr(char *str);
char			*ft_strndup(char *src, int n);
char			*ft_gnlstrjoin(char *s1, char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
#endif
