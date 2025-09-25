typedef struct _NDIS_RSS_SET_INDIRECTION_ENTRIES {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              RssEntrySize;
  ULONG              RssEntryTableOffset;
  ULONG              NumberOfRssEntries;
} NDIS_RSS_SET_INDIRECTION_ENTRIES, *PNDIS_RSS_SET_INDIRECTION_ENTRIES;