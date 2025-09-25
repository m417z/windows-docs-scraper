typedef struct _DHCP_CLIENT_FILTER_STATUS_INFO {
  DHCP_IP_ADDRESS  ClientIpAddress;
  DHCP_IP_MASK     SubnetMask;
  DHCP_CLIENT_UID  ClientHardwareAddress;
  LPWSTR           ClientName;
  LPWSTR           ClientComment;
  DATE_TIME        ClientLeaseExpires;
  DHCP_HOST_INFO   OwnerHost;
  BYTE             bClientType;
  BYTE             AddressState;
  QuarantineStatus Status;
  DATE_TIME        ProbationEnds;
  BOOL             QuarantineCapable;
  DWORD            FilterStatus;
} DHCP_CLIENT_FILTER_STATUS_INFO, *LPDHCP_CLIENT_FILTER_STATUS_INFO;