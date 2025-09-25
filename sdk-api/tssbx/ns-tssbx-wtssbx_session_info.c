typedef struct __MIDL_IWTSSBPlugin_0009 {
  WCHAR                wszUserName[105];
  WCHAR                wszDomainName[257];
  WCHAR                ApplicationType[257];
  DWORD                dwSessionId;
  FILETIME             CreateTime;
  FILETIME             DisconnectTime;
  WTSSBX_SESSION_STATE SessionState;
} WTSSBX_SESSION_INFO;