typedef struct _HIDP_DEVICE_DESC {
  PHIDP_COLLECTION_DESC CollectionDesc;
  ULONG                 CollectionDescLength;
  PHIDP_REPORT_IDS      ReportIDs;
  ULONG                 ReportIDsLength;
  HIDP_GETCOLDESC_DBG   Dbg;
} HIDP_DEVICE_DESC, *PHIDP_DEVICE_DESC;