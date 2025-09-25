typedef enum _DHCP_SUBNET_STATE {
  DhcpSubnetEnabled = 0,
  DhcpSubnetDisabled,
  DhcpSubnetEnabledSwitched,
  DhcpSubnetDisabledSwitched,
  DhcpSubnetInvalidState
} DHCP_SUBNET_STATE, *LPDHCP_SUBNET_STATE;