typedef struct _IDPE_ATTR {
  USHORT PeAttribLength;
  UCHAR  PeAttribType;
  UCHAR  PeAttribSubType;
  UCHAR  PeAttribValue[4];
} IDPE_ATTR, *LPIDPE_ATTR;