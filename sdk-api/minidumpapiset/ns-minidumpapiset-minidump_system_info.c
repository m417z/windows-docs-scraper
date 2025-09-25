typedef struct _MINIDUMP_SYSTEM_INFO {
  USHORT          ProcessorArchitecture;
  USHORT          ProcessorLevel;
  USHORT          ProcessorRevision;
  union {
    USHORT Reserved0;
    struct {
      UCHAR NumberOfProcessors;
      UCHAR ProductType;
    };
  };
  ULONG32         MajorVersion;
  ULONG32         MinorVersion;
  ULONG32         BuildNumber;
  ULONG32         PlatformId;
  RVA             CSDVersionRva;
  union {
    ULONG32 Reserved1;
    struct {
      USHORT SuiteMask;
      USHORT Reserved2;
    };
  };
  CPU_INFORMATION Cpu;
} MINIDUMP_SYSTEM_INFO, *PMINIDUMP_SYSTEM_INFO;