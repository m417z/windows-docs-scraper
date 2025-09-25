typedef struct _DHCP_SUBNET_ELEMENT_DATA {
  DHCP_SUBNET_ELEMENT_TYPE   ElementType;
#if ...
  union {
    DHCP_IP_RANGE       *IpRange;
    DHCP_HOST_INFO      *SecondaryHost;
    DHCP_IP_RESERVATION *ReservedIp;
    DHCP_IP_RANGE       *ExcludeIpRange;
    DHCP_IP_CLUSTER     *IpUsedCluster;
  } Element;
#if ...
  _DHCP_SUBNET_ELEMENT_UNION _DHCP_SUBNET_ELEMENT_UNION;
#else
  union {
    DHCP_IP_RANGE       *IpRange;
    DHCP_HOST_INFO      *SecondaryHost;
    DHCP_IP_RESERVATION *ReservedIp;
    DHCP_IP_RANGE       *ExcludeIpRange;
    DHCP_IP_CLUSTER     *IpUsedCluster;
  } Element;
#endif
#else
  _DHCP_SUBNET_ELEMENT_UNION _DHCP_SUBNET_ELEMENT_UNION;
#endif
} DHCP_SUBNET_ELEMENT_DATA, *LPDHCP_SUBNET_ELEMENT_DATA;