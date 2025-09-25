typedef struct _MDL {
  struct _MDL      *Next;
  CSHORT           Size;
  CSHORT           MdlFlags;
  struct _EPROCESS *Process;
  PVOID            MappedSystemVa;
  PVOID            StartVa;
  ULONG            ByteCount;
  ULONG            ByteOffset;
} MDL, *PMDL;