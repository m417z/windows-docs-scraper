typedef struct _PRM_MODULE_INFORMATION {
  USHORT  Revision;
  USHORT  Length;
  GUID    Identifier;
  USHORT  MajorVersion;
  USHORT  MinorVersion;
  USHORT  HandlerCount;
  ULONG   HandlerOffset;
  ULONG64 MmioRangesPhysicalAddress;
} PRM_MODULE_INFORMATION, *PPRM_MODULE_INFORMATION;