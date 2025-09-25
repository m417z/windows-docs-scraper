typedef struct _PRM_HANDLER_INFORMATION {
  USHORT  Revision;
  USHORT  Length;
  GUID    Identifier;
  ULONG64 PhysicalAddress;
  ULONG64 StaticBufferPhysicalAddress;
  ULONG64 AcpiParameterPhysicalAddress;
} PRM_HANDLER_INFORMATION, *PPRM_HANDLER_INFORMATION;