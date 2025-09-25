typedef struct _ISCSI_Path {
  ULONGLONG UniqueConnectionId;
  ULONGLONG EstimatedLinkSpeed;
  ULONG     PathWeight;
  ULONG     PrimaryPath;
  ULONG     ConnectionStatus;
  ULONG     TCPOffLoadAvailable;
} ISCSI_Path, *PISCSI_Path;