typedef struct _WSMAN_RECEIVE_DATA_RESULT {
  PCWSTR     streamId;
  WSMAN_DATA streamData;
  PCWSTR     commandState;
  DWORD      exitCode;
} WSMAN_RECEIVE_DATA_RESULT;