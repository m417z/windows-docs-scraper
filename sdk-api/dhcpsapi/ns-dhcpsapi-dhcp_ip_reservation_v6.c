typedef struct _DHCP_IP_RESERVATION_V6 {
  DHCP_IPV6_ADDRESS ReservedIpAddress;
  DHCP_CLIENT_UID   *ReservedForClient;
  DWORD             InterfaceId;
} DHCP_IP_RESERVATION_V6, *LPDHCP_IP_RESERVATION_V6;