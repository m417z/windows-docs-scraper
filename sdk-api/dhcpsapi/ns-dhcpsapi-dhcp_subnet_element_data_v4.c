typedef struct _DHCP_SUBNET_ELEMENT_DATA_V4 {
  DHCP_SUBNET_ELEMENT_TYPE      ElementType;
#if ...
  union {
    DHCP_IP_RANGE          *IpRange;
    DHCP_HOST_INFO         *SecondaryHost;
    DHCP_IP_RESERVATION_V4 *ReservedIp;
    DHCP_IP_RANGE          *ExcludeIpRange;
    DHCP_IP_CLUSTER        *IpUsedCluster;
  } Element;
#if ...
  _DHCP_SUBNET_ELEMENT_UNION_V4 _DHCP_SUBNET_ELEMENT_UNION_V4;
#else
  union {
    DHCP_IP_RANGE          *IpRange;
    DHCP_HOST_INFO         *SecondaryHost;
    DHCP_IP_RESERVATION_V4 *ReservedIp;
    DHCP_IP_RANGE          *ExcludeIpRange;
    DHCP_IP_CLUSTER        *IpUsedCluster;
  } Element;
#endif
#else
  _DHCP_SUBNET_ELEMENT_UNION_V4 _DHCP_SUBNET_ELEMENT_UNION_V4;
#endif
} DHCP_SUBNET_ELEMENT_DATA_V4, *LPDHCP_SUBNET_ELEMENT_DATA_V4;