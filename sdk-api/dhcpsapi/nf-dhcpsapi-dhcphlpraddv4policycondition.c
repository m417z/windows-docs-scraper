DWORD DHCP_API_FUNCTION DhcpHlprAddV4PolicyCondition(
  [in, out] LPDHCP_POLICY       Policy,
  [in]      DWORD               ParentExpr,
  [in]      DHCP_POL_ATTR_TYPE  Type,
  [in]      DWORD               OptionID,
  [in]      DWORD               SubOptionID,
  [in]      LPWSTR              VendorName,
  [in]      DHCP_POL_COMPARATOR Operator,
            LPBYTE              Value,
  [in]      DWORD               ValueLength,
  [out]     DWORD               *ConditionIndex
);