typedef struct _WINHTTP_HOST_CONNECTION_GROUP {
  PCWSTR                    pwszHost;
  ULONG                     cConnectionGroups;
  PWINHTTP_CONNECTION_GROUP pConnectionGroups;
} WINHTTP_HOST_CONNECTION_GROUP, *PWINHTTP_HOST_CONNECTION_GROUP;