typedef struct icmp_error_info {
  SOCKADDR_INET srcaddress;
  IPPROTO       protocol;
  UINT8         type;
  UINT8         code;
} ICMP_ERROR_INFO, *PICMP_ERROR_INFO;