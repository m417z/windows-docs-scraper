typedef struct _BAND_SECURITY_INFO {
  ULONG      StructSize;
  LOCKSTATE  ReadLock;
  LOCKSTATE  WriteLock;
  ALGOIDTYPE CryptoAlgoIdType;
  union {
    struct {
      ULONG Offset;
      ULONG Length;
    } CryptoAlgoOidString;
    ULONG CryptoAlgoNumericId;
  };
  BYTE       Metadata[32];
} BAND_SECURITY_INFO, *PBAND_SECURITY_INFO;