typedef struct _NDIS_NDK_LOCAL_ENDPOINT_ENTRY {
  SOCKADDR_INET Local;
  BOOLEAN       UserModeOwner;
  BOOLEAN       Listener;
  ULONG         OwnerPid;
} NDIS_NDK_LOCAL_ENDPOINT_ENTRY;