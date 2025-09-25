typedef enum {
  DhcpUpdatePolicyName = 0x00000001,
  DhcpUpdatePolicyOrder = 0x00000002,
  DhcpUpdatePolicyExpr = 0x00000004,
  DhcpUpdatePolicyRanges = 0x00000008,
  DhcpUpdatePolicyDescr = 0x00000010,
  DhcpUpdatePolicyStatus = 0x00000020,
  DhcpUpdatePolicyDnsSuffix = 0x00000040
} DHCP_POLICY_FIELDS_TO_UPDATE;