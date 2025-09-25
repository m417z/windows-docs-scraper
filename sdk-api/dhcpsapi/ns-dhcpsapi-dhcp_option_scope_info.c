typedef struct _DHCP_OPTION_SCOPE_INFO {
  DHCP_OPTION_SCOPE_TYPE   ScopeType;
#if ...
  union {
    DHCP_IP_ADDRESS     SubnetScopeInfo;
    DHCP_RESERVED_SCOPE ReservedScopeInfo;
    LPWSTR              MScopeInfo;
  } ScopeInfo;
#if ...
  _DHCP_OPTION_SCOPE_UNION _DHCP_OPTION_SCOPE_UNION;
#else
  union {
    PVOID               DefaultScopeInfo;
    PVOID               GlobalScopeInfo;
    DHCP_IP_ADDRESS     SubnetScopeInfo;
    DHCP_RESERVED_SCOPE ReservedScopeInfo;
    LPWSTR              MScopeInfo;
  } ScopeInfo;
#endif
#else
  _DHCP_OPTION_SCOPE_UNION _DHCP_OPTION_SCOPE_UNION;
#endif
} DHCP_OPTION_SCOPE_INFO, *LPDHCP_OPTION_SCOPE_INFO;