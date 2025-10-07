typedef struct _FRAME_DESCRIPTOR {
  LPBYTE       FramePointer;
  __int64      TimeStamp;
  DWORD        FrameLength;
  DWORD        nBytesAvail;
  WORD         Etype;
  BYTE         Sap;
  BYTE         LowProtocol;
  WORD         LowProtocolOffset;
  GENERIC_PORT HighPort;
  WORD         HighProtocolOffset;
} FRAME_DESCRIPTOR, *LPFRAME_DESCRIPTOR;