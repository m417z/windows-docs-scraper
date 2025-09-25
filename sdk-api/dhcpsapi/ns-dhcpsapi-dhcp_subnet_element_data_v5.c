typedef struct _DHCP_SUBNET_ELEMENT_DATA_V5 {
  DHCP_SUBNET_ELEMENT_TYPE      ElementType;
#if ...
  union {
    DHCP_BOOTP_IP_RANGE    *IpRange;
    DHCP_HOST_INFO         *SecondaryHost;
    DHCP_IP_RESERVATION_V4 *ReservedIp;
    DHCP_IP_RANGE          *ExcludeIpRange;
    DHCP_IP_CLUSTER        *IpUsedCluster;
  } Element;
#if ...
  _DHCP_SUBNET_ELEMENT_UNION_V5 _DHCP_SUBNET_ELEMENT_UNION_V5;
#else
  union {
    DHCP_BOOTP_IP_RANGE    *IpRange;
    DHCP_HOST_INFO         *SecondaryHost;
    DHCP_IP_RESERVATION_V4 *ReservedIp;
    DHCP_IP_RANGE          *ExcludeIpRange;
    DHCP_IP_CLUSTER        *IpUsedCluster;
  } Element;
#endif
#else
  _DHCP_SUBNET_ELEMENT_UNION_V5 _DHCP_SUBNET_ELEMENT_UNION_V5;
#endif
} DHCP_SUBNET_ELEMENT_DATA_V5, *LPDHCP_SUBNET_ELEMENT_DATA_V5;