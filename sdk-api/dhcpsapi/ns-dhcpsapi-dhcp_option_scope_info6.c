typedef struct _DHCP_OPTION_SCOPE_INFO6 {
  DHCP_OPTION_SCOPE_TYPE6   ScopeType;
#if ...
  union {
    DHCP_IPV6_ADDRESS    SubnetScopeInfo;
    DHCP_RESERVED_SCOPE6 ReservedScopeInfo;
  } ScopeInfo;
#if ...
  _DHCP_OPTION_SCOPE_UNION6 _DHCP_OPTION_SCOPE_UNION6;
#else
  union {
    PVOID                DefaultScopeInfo;
    DHCP_IPV6_ADDRESS    SubnetScopeInfo;
    DHCP_RESERVED_SCOPE6 ReservedScopeInfo;
  } ScopeInfo;
#endif
#else
  _DHCP_OPTION_SCOPE_UNION6 _DHCP_OPTION_SCOPE_UNION6;
#endif
} DHCP_OPTION_SCOPE_INFO6, *LPDHCP_OPTION_SCOPE_INFO6;