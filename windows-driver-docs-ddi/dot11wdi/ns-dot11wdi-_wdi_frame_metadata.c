typedef struct _WDI_FRAME_METADATA {
  LIST_ENTRY       Linkage;
  PNET_BUFFER_LIST pNBL;
  WDI_FRAME_ID     FrameID;
  UINT16           wPad;
  UINT32           dPad;
  union {
    WDI_TX_METADATA txMetaData;
    WDI_RX_METADATA rxMetaData;
  } u;
} WDI_FRAME_METADATA, *PWDI_FRAME_METADATA;