typedef struct _KSPROCESSPIN {
  PKSPIN            Pin;
  PKSSTREAM_POINTER StreamPointer;
  PKSPROCESSPIN     InPlaceCounterpart;
  PKSPROCESSPIN     DelegateBranch;
  PKSPROCESSPIN     CopySource;
  PVOID             Data;
  ULONG             BytesAvailable;
  ULONG             BytesUsed;
  ULONG             Flags;
  BOOLEAN           Terminate;
} KSPROCESSPIN, *PKSPROCESSPIN;