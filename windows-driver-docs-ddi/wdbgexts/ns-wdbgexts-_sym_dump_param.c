typedef struct _SYM_DUMP_PARAM {
  ULONG                    size;
  PUCHAR                   sName;
  ULONG                    Options;
  ULONG64                  addr;
  PFIELD_INFO              listLink;
  union {
    PVOID Context;
    PVOID pBuffer;
  };
  PSYM_DUMP_FIELD_CALLBACK CallbackRoutine;
  ULONG                    nFields;
  PFIELD_INFO              Fields;
  ULONG64                  ModBase;
  ULONG                    TypeId;
  ULONG                    TypeSize;
  ULONG                    BufferSize;
  ULONG                    fPointer : 2;
  ULONG                    fArray : 1;
  ULONG                    fStruct : 1;
  ULONG                    fConstant : 1;
  ULONG                    Reserved : 27;
} SYM_DUMP_PARAM, *PSYM_DUMP_PARAM;