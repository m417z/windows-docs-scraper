typedef struct _MINIDUMP_HEADER {
  ULONG32 Signature;
  ULONG32 Version;
  ULONG32 NumberOfStreams;
  RVA     StreamDirectoryRva;
  ULONG32 CheckSum;
  union {
    ULONG32 Reserved;
    ULONG32 TimeDateStamp;
  };
  ULONG64 Flags;
} MINIDUMP_HEADER, *PMINIDUMP_HEADER;