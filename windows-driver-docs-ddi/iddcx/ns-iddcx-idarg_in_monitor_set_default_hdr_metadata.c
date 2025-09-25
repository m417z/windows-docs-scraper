struct IDARG_IN_MONITOR_SET_DEFAULT_HDR_METADATA {
  IDDCX_DEFAULT_HDR_METADATA_TYPE Type;
  UINT                            Size;
  union {
    IDDCX_HDR10_METADATA *pHdr10;
  } Data;
};