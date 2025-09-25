typedef struct addrinfo_dns_server {
  unsigned int     ai_servertype;
  unsigned __int64 ai_flags;
  unsigned int     ai_addrlen;
  struct sockaddr  *ai_addr;
  union {
    PWSTR ai_template;
  };
} ADDRINFO_DNS_SERVER;