typedef struct _FIELD_INFO {
  PUCHAR    fName;
  PUCHAR    printName;
  ULONG     size;
  ULONG     fOptions;
  ULONG64   address;
  union {
    PVOID fieldCallBack;
    PVOID pBuffer;
  };
  ULONG     TypeId;
  ULONG     FieldOffset;
  ULONG     BufferSize;
  struct {
    USHORT Position;
    USHORT Size;
  } BitField;
  _BitField _BitField;
  ULONG     fPointer : 2;
  ULONG     fArray : 1;
  ULONG     fStruct : 1;
  ULONG     fConstant : 1;
  ULONG     fStatic : 1;
  ULONG     Reserved : 26;
} FIELD_INFO, *PFIELD_INFO;