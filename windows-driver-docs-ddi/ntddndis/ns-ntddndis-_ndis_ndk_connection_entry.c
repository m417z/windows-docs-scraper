typedef struct _NDIS_NDK_CONNECTION_ENTRY {
  SOCKADDR_INET Local;
  SOCKADDR_INET Remote;
  BOOLEAN       UserModeOwner;
  ULONG         OwnerPid;
} NDIS_NDK_CONNECTION_ENTRY;