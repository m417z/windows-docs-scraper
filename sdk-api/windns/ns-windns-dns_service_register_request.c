typedef struct _DNS_SERVICE_REGISTER_REQUEST {
  ULONG                          Version;
  ULONG                          InterfaceIndex;
  PDNS_SERVICE_INSTANCE          pServiceInstance;
  PDNS_SERVICE_REGISTER_COMPLETE pRegisterCompletionCallback;
  PVOID                          pQueryContext;
  HANDLE                         hCredentials;
  BOOL                           unicastEnabled;
} DNS_SERVICE_REGISTER_REQUEST, *PDNS_SERVICE_REGISTER_REQUEST;