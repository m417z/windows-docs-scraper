typedef struct _DXGK_HISTORY_BUFFER {
  DXGK_HISTORY_BUFFER_HEADER Header;
  UINT8                      DriverPrivateData[1];
} DXGK_HISTORY_BUFFER;