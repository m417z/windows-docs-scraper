typedef struct _NDIS_RECEIVE_SCALE_PARAMETERS_V2 {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              HashInformation;
  ULONG              HashSecretKeySize;
  ULONG              HashSecretKeyOffset;
  ULONG              NumberOfQueues;
  ULONG              NumberOfIndirectionTableEntries;
} NDIS_RECEIVE_SCALE_PARAMETERS_V2, *PNDIS_RECEIVE_SCALE_PARAMETERS_V2;