typedef struct fd_set {
  u_int  fd_count;
  SOCKET fd_array[FD_SETSIZE];
} fd_set, FD_SET, *PFD_SET, *LPFD_SET;