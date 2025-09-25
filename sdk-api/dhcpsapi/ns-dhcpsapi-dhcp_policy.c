typedef struct _DHCP_POLICY {
  LPWSTR                PolicyName;
  BOOL                  IsGlobalPolicy;
  DHCP_IP_ADDRESS       Subnet;
  DWORD                 ProcessingOrder;
  LPDHCP_POL_COND_ARRAY Conditions;
  LPDHCP_POL_EXPR_ARRAY Expressions;
  LPDHCP_IP_RANGE_ARRAY Ranges;
  LPWSTR                Description;
  BOOL                  Enabled;
} DHCP_POLICY, *PDHCP_POLICY, *LPDHCP_POLICY;