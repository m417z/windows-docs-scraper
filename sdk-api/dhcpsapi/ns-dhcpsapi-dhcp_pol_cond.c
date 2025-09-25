typedef struct _DHCP_POL_COND {
  DWORD               ParentExpr;
  DHCP_POL_ATTR_TYPE  Type;
  DWORD               OptionID;
  DWORD               SubOptionID;
  LPWSTR              VendorName;
  DHCP_POL_COMPARATOR Operator;
  LPBYTE              Value;
  DWORD               ValueLength;
} DHCP_POL_COND, *PDHCP_POL_COND, *LPDHCP_POL_COND;