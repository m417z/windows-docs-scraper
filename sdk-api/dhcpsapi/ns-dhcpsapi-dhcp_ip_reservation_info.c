typedef struct _DHCP_IP_RESERVATION_INFO {
  DHCP_IP_ADDRESS ReservedIpAddress;
  DHCP_CLIENT_UID ReservedForClient;
  LPWSTR          ReservedClientName;
  LPWSTR          ReservedClientDesc;
  BYTE            bAllowedClientTypes;
  BYTE            fOptionsPresent;
} DHCP_IP_RESERVATION_INFO, *LPDHCP_IP_RESERVATION_INFO;