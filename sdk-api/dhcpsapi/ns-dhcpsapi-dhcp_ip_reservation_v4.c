typedef struct _DHCP_IP_RESERVATION_V4 {
  DHCP_IP_ADDRESS ReservedIpAddress;
  DHCP_CLIENT_UID *ReservedForClient;
  BYTE            bAllowedClientTypes;
} DHCP_IP_RESERVATION_V4, *LPDHCP_IP_RESERVATION_V4;