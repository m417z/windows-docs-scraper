typedef struct _NFC_CX_LLCP_CONFIG {
  ULONG  Size;
  USHORT Miu;
  UCHAR  LinkTimeout;
  UCHAR  RecvWindowSize;
} NFC_CX_LLCP_CONFIG, *PNFC_CX_LLCP_CONFIG;