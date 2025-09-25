typedef struct {
  DXGK_MIRACAST_CHUNK_INFO ChunkInfo;
  UINT                     PrivateDriverDataSize;
  BYTE                     PrivateDriverData[1];
} D3DKMT_MIRACAST_CHUNK_DATA;