typedef struct _EFI_SET_VARIABLE_IN {
  ULONG  VariableNameOffset;
  GUID   VendorGuid;
  ULONG  Attributes;
  SIZE_T DataSize;
  ULONG  DataOffset;
  BYTE   Buffer[ANYSIZE_ARRAY];
} EFI_SET_VARIABLE_IN, *PEFI_SET_VARIABLE_IN;