typedef struct {
  DXGK_MIRACAST_CHUNK_TYPE ChunkType;
  DXGK_MIRACAST_CHUNK_ID   ChunkId;
  UINT                     ProcessingTime;
  UINT                     EncodeRate;
} DXGK_MIRACAST_CHUNK_INFO;