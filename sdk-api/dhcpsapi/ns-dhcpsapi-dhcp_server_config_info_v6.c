typedef struct _DHCP_SERVER_CONFIG_INFO_V6 {
  BOOL  UnicastFlag;
  BOOL  RapidCommitFlag;
  DWORD PreferredLifetime;
  DWORD ValidLifetime;
  DWORD T1;
  DWORD T2;
  DWORD PreferredLifetimeIATA;
  DWORD ValidLifetimeIATA;
  BOOL  fAuditLog;
} DHCP_SERVER_CONFIG_INFO_V6, *LPDHCP_SERVER_CONFIG_INFO_V6;