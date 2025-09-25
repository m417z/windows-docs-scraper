typedef struct _AACS_READ_BINDING_NONCE {
  DVD_SESSION_ID SessionId;
  ULONG          NumberOfSectors;
  ULONGLONG      StartLba;
  union {
    HANDLE    Handle;
    ULONGLONG ForceStructureLengthToMatch64bit;
  };
} AACS_READ_BINDING_NONCE, *PAACS_READ_BINDING_NONCE;