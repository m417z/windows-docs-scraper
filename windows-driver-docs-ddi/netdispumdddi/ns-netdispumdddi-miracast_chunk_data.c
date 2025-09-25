typedef struct {
  MIRACAST_CHUNK_INFO ChunkInfo;
  UINT                PrivateDriverDataSize;
  UCHAR               PrivateDriverData[1];
} MIRACAST_CHUNK_DATA;