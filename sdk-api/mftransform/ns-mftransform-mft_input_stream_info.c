typedef struct _MFT_INPUT_STREAM_INFO {
  LONGLONG hnsMaxLatency;
  DWORD    dwFlags;
  DWORD    cbSize;
  DWORD    cbMaxLookahead;
  DWORD    cbAlignment;
} MFT_INPUT_STREAM_INFO;