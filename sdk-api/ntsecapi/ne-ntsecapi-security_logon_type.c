typedef enum _SECURITY_LOGON_TYPE {
  UndefinedLogonType = 0,
  Interactive = 2,
  Network,
  Batch,
  Service,
  Proxy,
  Unlock,
  NetworkCleartext,
  NewCredentials,
  RemoteInteractive,
  CachedInteractive,
  CachedRemoteInteractive,
  CachedUnlock
} SECURITY_LOGON_TYPE, *PSECURITY_LOGON_TYPE;