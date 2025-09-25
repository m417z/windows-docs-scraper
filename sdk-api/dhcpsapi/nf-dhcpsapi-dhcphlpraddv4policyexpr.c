DWORD DHCP_API_FUNCTION DhcpHlprAddV4PolicyExpr(
  [in, out] LPDHCP_POLICY       Policy,
  [in]      DWORD               ParentExpr,
  [in]      DHCP_POL_LOGIC_OPER Operator,
  [out]     DWORD               *ExprIndex
);