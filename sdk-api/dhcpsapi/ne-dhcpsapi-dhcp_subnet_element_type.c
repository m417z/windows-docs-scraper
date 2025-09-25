typedef enum _DHCP_SUBNET_ELEMENT_TYPE_V5 {
  DhcpIpRanges,
  DhcpSecondaryHosts,
  DhcpReservedIps,
  DhcpExcludedIpRanges,
  DhcpIpUsedClusters,
  DhcpIpRangesDhcpOnly,
  DhcpIpRangesDhcpBootp,
  DhcpIpRangesBootpOnly
} DHCP_SUBNET_ELEMENT_TYPE, *LPDHCP_SUBNET_ELEMENT_TYPE;