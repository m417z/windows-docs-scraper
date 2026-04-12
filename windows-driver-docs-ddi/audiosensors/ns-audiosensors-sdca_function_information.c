typedef struct _SDCA_FUNCTION_INFORMATION {
  ULONG  Size;
  UINT8  Version;
  UINT8  FunctionNumber;
  UINT8  FunctionType;
  UINT16 FunctionManufacturerId;
  UINT16 FunctionId;
  UINT8  ControllerId;
  UINT8  LinkId;
  UINT8  UniqueId;
} SDCA_FUNCTION_INFORMATION, *PSDCA_FUNCTION_INFORMATION;