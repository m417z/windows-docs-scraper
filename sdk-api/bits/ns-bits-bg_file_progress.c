typedef struct _BG_FILE_PROGRESS {
  UINT64 BytesTotal;
  UINT64 BytesTransferred;
  BOOL   Completed;
} BG_FILE_PROGRESS;