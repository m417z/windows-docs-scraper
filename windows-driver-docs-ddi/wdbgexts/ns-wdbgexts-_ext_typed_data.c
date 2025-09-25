typedef struct _EXT_TYPED_DATA {
  IN EXT_TDOP          Operation;
  IN ULONG             Flags;
  IN DEBUG_TYPED_DATA  InData;
  OUT DEBUG_TYPED_DATA OutData;
  IN ULONG             InStrIndex;
  IN ULONG             In32;
  OUT ULONG            Out32;
  IN ULONG64           In64;
  OUT ULONG64          Out64;
  OUT ULONG            StrBufferIndex;
  IN ULONG             StrBufferChars;
  OUT ULONG            StrCharsNeeded;
  IN OUT ULONG         DataBufferIndex;
  IN ULONG             DataBufferBytes;
  OUT ULONG            DataBytesNeeded;
  OUT HRESULT          Status;
  ULONG64              Reserved[8];
} EXT_TYPED_DATA, *PEXT_TYPED_DATA;