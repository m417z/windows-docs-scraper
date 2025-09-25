typedef struct _DXGKARG_FORMATHISTORYBUFFER {
  DXGK_HISTORY_BUFFER            *pHistoryBuffer;
  UINT32                         HistoryBufferSize;
  PVOID                          pFormattedBuffer;
  UINT32                         FormattedBufferSize;
  UINT32                         NumTimestamps;
  DXGKARG_HISTORYBUFFERPRECISION Precision;
  UINT32                         Offset;
} DXGKARG_FORMATHISTORYBUFFER;