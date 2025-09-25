typedef struct _DEBUG_REGISTER_DESCRIPTION {
  ULONG   Type;
  ULONG   Flags;
  ULONG   SubregMaster;
  ULONG   SubregLength;
  ULONG64 SubregMask;
  ULONG   SubregShift;
  ULONG   Reserved0;
} DEBUG_REGISTER_DESCRIPTION, *PDEBUG_REGISTER_DESCRIPTION;