typedef struct _WSACMSGHDR {
  SIZE_T cmsg_len;
  INT    cmsg_level;
  INT    cmsg_type;
} WSACMSGHDR, *PWSACMSGHDR, *LPWSACMSGHDR;