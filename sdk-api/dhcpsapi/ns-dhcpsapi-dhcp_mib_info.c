typedef struct _DHCP_MIB_INFO {
  DWORD            Discovers;
  DWORD            Offers;
  DWORD            Requests;
  DWORD            Acks;
  DWORD            Naks;
  DWORD            Declines;
  DWORD            Releases;
  DATE_TIME        ServerStartTime;
  DWORD            Scopes;
  LPSCOPE_MIB_INFO ScopeInfo;
} DHCP_MIB_INFO, *LPDHCP_MIB_INFO;