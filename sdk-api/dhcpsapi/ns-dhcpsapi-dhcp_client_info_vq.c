typedef struct _DHCP_CLIENT_INFO_VQ {
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
} DHCP_CLIENT_INFO_VQ, *LPDHCP_CLIENT_INFO_VQ;