typedef struct _DXVA_Tile_AV1 {
  UINT   DataOffset;
  UINT   DataSize;
  USHORT row;
  USHORT column;
  UINT16 Reserved16Bits;
  UCHAR  anchor_frame;
  UCHAR  Reserved8Bits;
} DXVA_Tile_AV1, *LPDXVA_Tile_AV1;