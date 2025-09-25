typedef struct _DHCP_MIB_INFO_V6 {
  DWORD               Solicits;
  DWORD               Advertises;
  DWORD               Requests;
  DWORD               Renews;
  DWORD               Rebinds;
  DWORD               Replies;
  DWORD               Confirms;
  DWORD               Declines;
  DWORD               Releases;
  DWORD               Informs;
  DATE_TIME           ServerStartTime;
  DWORD               Scopes;
  LPSCOPE_MIB_INFO_V6 ScopeInfo;
} DHCP_MIB_INFO_V6, *LPDHCP_MIB_INFO_V6;