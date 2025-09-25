typedef struct _MFFOLDDOWN_MATRIX {
  UINT32 cbSize;
  UINT32 cSrcChannels;
  UINT32 cDstChannels;
  UINT32 dwChannelMask;
  LONG   Coeff[64];
} MFFOLDDOWN_MATRIX;