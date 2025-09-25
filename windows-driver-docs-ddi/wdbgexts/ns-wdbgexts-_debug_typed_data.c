typedef struct _DEBUG_TYPED_DATA {
  ULONG64 ModBase;
  ULONG64 Offset;
  ULONG64 EngineHandle;
  ULONG64 Data;
  ULONG   Size;
  ULONG   Flags;
  ULONG   TypeId;
  ULONG   BaseTypeId;
  ULONG   Tag;
  ULONG   Register;
  ULONG64 Internal[9];
} DEBUG_TYPED_DATA, *PDEBUG_TYPED_DATA;