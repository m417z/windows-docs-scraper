typedef struct _BTH_QUERY_SERVICE {
  ULONG             type;
  ULONG             serviceHandle;
  SdpQueryUuid      uuids[MAX_UUIDS_IN_QUERY];
  ULONG             numRange;
  SdpAttributeRange pRange[1];
} BTH_QUERY_SERVICE, *PBTH_QUERY_SERVICE, BTHNS_RESTRICTIONBLOB, *PBTHNS_RESTRICTIONBLOB;