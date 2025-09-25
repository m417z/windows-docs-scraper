typedef struct _DHCP_POL_EXPR {
  DWORD               ParentExpr;
  DHCP_POL_LOGIC_OPER Operator;
} DHCP_POL_EXPR, *PDHCP_POL_EXPR, *LPDHCP_POL_EXPR;