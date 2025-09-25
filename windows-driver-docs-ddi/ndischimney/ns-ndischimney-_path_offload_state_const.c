typedef struct _PATH_OFFLOAD_STATE_CONST {
  OFFLOAD_STATE_HEADER Header;
  const UCHAR          *SourceAddress;
  const UCHAR          *DestinationAddress;
} PATH_OFFLOAD_STATE_CONST, *PPATH_OFFLOAD_STATE_CONST;