typedef struct _MDNS_QUERY_HANDLE {
  WCHAR nameBuf[DNS_MAX_NAME_BUFFER_LENGTH];
  WORD  wType;
  PVOID pSubscription;
  PVOID pWnfCallbackParams;
  ULONG stateNameData[2];
} MDNS_QUERY_HANDLE, *PMDNS_QUERY_HANDLE;