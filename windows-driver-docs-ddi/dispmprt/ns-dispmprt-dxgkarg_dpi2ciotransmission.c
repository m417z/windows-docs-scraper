typedef struct _DXGKARG_DPI2CIOTRANSMISSION {
  struct {
    UINT Read : 1;
    UINT Write : 1;
    UINT EDDCMode : 1;
    UINT OffsetSizeInBytes : 3;
    UINT CanUseCachedData : 1;
    UINT Reserved : 25;
  };
  UINT   RootPortIndex;
  UINT   I2CAddress;
  union {
    struct {
      UINT WordOffset : 8;
      UINT SegmentPointer : 7;
      UINT Reserved1 : 17;
    };
    UINT Offset;
  };
  UINT   BufferSizeSupplied;
  UINT   BytesToWrite;
  UINT   BytesToRead;
  UINT   DPNativeError;
  UINT   BytesWritten;
  UINT   BytesRead;
  BYTE   Data[1];
} DXGKARG_DPI2CIOTRANSMISSION, *PDXGKARG_DPI2CIOTRANSMISSION;