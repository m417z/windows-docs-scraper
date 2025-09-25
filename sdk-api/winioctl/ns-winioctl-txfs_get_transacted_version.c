typedef struct _TXFS_GET_TRANSACTED_VERSION {
  DWORD ThisBaseVersion;
  DWORD LatestVersion;
  WORD  ThisMiniVersion;
  WORD  FirstMiniVersion;
  WORD  LatestMiniVersion;
} TXFS_GET_TRANSACTED_VERSION, *PTXFS_GET_TRANSACTED_VERSION;