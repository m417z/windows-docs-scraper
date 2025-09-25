typedef struct _NDIS_RSS_PROCESSOR {
  PROCESSOR_NUMBER ProcNum;
  USHORT           PreferenceIndex;
  USHORT           Reserved;
} NDIS_RSS_PROCESSOR, *PNDIS_RSS_PROCESSOR;