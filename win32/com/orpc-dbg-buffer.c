typedef struct _ORPC_DBG_BUFFER {
  DWORD alwaysOrSometimes;
  BYTE  verMajor;
  BYTE  verMinor;
  DWORD cbRemaining;
  GUID  guidSemantic;
  union {
    BOOL   fStopOnOtherSide;
    USHORT wDebuggingOpCode;
    USHORT cExtent;
    BYTE   padding[2];
    struct {
      ULONG cb;
      GUID  guidExtent;
      BYTE  *rgbData;
    };
  };
} ORPC_DBG_BUFFER, *PORPC_DBG_BUFFER;