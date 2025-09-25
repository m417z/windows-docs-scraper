typedef struct _DXGKARG_DPSBMTRANSMISSION {
  struct {
    UINT CanUseCachedData : 1;
    UINT Reserved : 31;
  };
  UINT   RootPortIndex;
  UINT   BufferSizeSupplied;
  UINT   RequestLength;
  UINT   MaxReplyLength;
  UINT   DPNativeError;
  UINT   ActualReplyLength;
  BYTE   Data[1];
} DXGKARG_DPSBMTRANSMISSION, *PDXGKARG_DPSBMTRANSMISSION;