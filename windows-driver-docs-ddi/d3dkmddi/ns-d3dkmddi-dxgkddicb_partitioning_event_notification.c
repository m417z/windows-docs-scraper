typedef struct _DXGKDDICB_PARTITIONING_EVENT_NOTIFICATION {
  HANDLE                          hAdapter;
  DXGIDDI_PARTITIONING_EVENT_TYPE EventType;
  ULONG                           PartitionId;
  WCHAR                           EventDescription[DXGKDDI_PARTITION_EVENT_DESCRIPTION_MAX];
  UINT64                          EventData1;
  UINT64                          EventData2;
  UINT64                          EventData3;
  UINT64                          EventData4;
  UINT64                          EventData5;
} DXGKDDICB_PARTITIONING_EVENT_NOTIFICATION, *PDXGKDDICB_PARTITIONING_EVENT_NOTIFICATION;