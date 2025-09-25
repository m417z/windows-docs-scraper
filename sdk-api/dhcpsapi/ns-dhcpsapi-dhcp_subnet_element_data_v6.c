typedef struct _DHCP_SUBNET_ELEMENT_DATA_V6 {
  DHCP_SUBNET_ELEMENT_TYPE_V6   ElementType;
#if ...
  union {
    DHCP_IP_RANGE_V6       *IpRange;
    DHCP_IP_RESERVATION_V6 *ReservedIp;
    DHCP_IP_RANGE_V6       *ExcludeIpRange;
  } Element;
#if ...
  _DHCP_SUBNET_ELEMENT_UNION_V6 _DHCP_SUBNET_ELEMENT_UNION_V6;
#else
  union {
    DHCP_IP_RANGE_V6       *IpRange;
    DHCP_IP_RESERVATION_V6 *ReservedIp;
    DHCP_IP_RANGE_V6       *ExcludeIpRange;
  } Element;
#endif
#else
  _DHCP_SUBNET_ELEMENT_UNION_V6 _DHCP_SUBNET_ELEMENT_UNION_V6;
#endif
} DHCP_SUBNET_ELEMENT_DATA_V6, *LPDHCP_SUBNET_ELEMENT_DATA_V6;