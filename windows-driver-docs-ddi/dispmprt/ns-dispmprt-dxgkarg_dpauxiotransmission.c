typedef struct _DXGKARG_DPAUXIOTRANSMISSION {
  struct {
    UINT Write : 1;
    UINT CanUseCachedData : 1;
    UINT Reserved : 30;
  };
  UINT   RootPortIndex;
  UINT   DPCDAddress;
  BYTE   NumBytesRequested;
  UINT   DPNativeError;
  BYTE   NumBytesDone;
  BYTE   Data[MAX_DP_NATIVE_AUX_IO_SIZE];
} DXGKARG_DPAUXIOTRANSMISSION, *PDXGKARG_DPAUXIOTRANSMISSION;