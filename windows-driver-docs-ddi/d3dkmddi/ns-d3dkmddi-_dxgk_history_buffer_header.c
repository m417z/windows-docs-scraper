typedef struct _DXGK_HISTORY_BUFFER_HEADER {
  UINT32 RenderCbSequence;
  UINT32 NumTimestamps;
  UINT32 PrivateDataSize;
  UINT32 Reserved;
} DXGK_HISTORY_BUFFER_HEADER;