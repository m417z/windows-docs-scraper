typedef struct _DXVA_HuffmanTable_MJPEG {
  UINT8 bits_ac[4][16];
  UINT8 table_ac[4][256];
  UINT8 bits_dc[4][16];
  UINT8 table_dc[4][256];
} DXVA_HuffmanTable_MJPEG, *LPDXVA_HuffmanTable_MJPEG;