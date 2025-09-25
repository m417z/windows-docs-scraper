typedef struct pollfd {
  SOCKET fd;
  SHORT  events;
  SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, *LPWSAPOLLFD;