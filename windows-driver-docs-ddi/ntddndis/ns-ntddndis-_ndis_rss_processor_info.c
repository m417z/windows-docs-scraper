typedef struct _NDIS_RSS_PROCESSOR_INFO {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  PROCESSOR_NUMBER   RssBaseProcessor;
  ULONG              MaxNumRssProcessors;
  USHORT             PreferredNumaNode;
  ULONG              RssProcessorArrayOffset;
  ULONG              RssProcessorCount;
  ULONG              RssProcessorEntrySize;
  PROCESSOR_NUMBER   RssMaxProcessor;
  NDIS_RSS_PROFILE   RssProfile;
} NDIS_RSS_PROCESSOR_INFO, *PNDIS_RSS_PROCESSOR_INFO;