typedef struct _PKU2U_CREDUI_CONTEXT {
  ULONG64 Version;
  USHORT  cbHeaderLength;
  ULONG   cbStructureLength;
  USHORT  CertArrayCount;
  ULONG   CertArrayOffset;
} PKU2U_CREDUI_CONTEXT, *PPKU2U_CREDUI_CONTEXT;