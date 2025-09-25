typedef struct _EC_VARIANT {
  union {
    BOOL                            BooleanVal;
    UINT32                          UInt32Val;
    ULONGLONG                       DateTimeVal;
    LPCWSTR                         StringVal;
    PBYTE                           BinaryVal;
    BOOL                            *BooleanArr;
    INT32                           *Int32Arr;
    LPWSTR                          *StringArr;
    EC_OBJECT_ARRAY_PROPERTY_HANDLE PropertyHandleVal;
  };
  DWORD Count;
  DWORD Type;
} EC_VARIANT, *PEC_VARIANT;