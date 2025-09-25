typedef struct _EFI_GET_NEXT_VARIABLE_NAME_OUT {
  EFI_VARIABLE_STATUS EfiStatus;
  GUID                VendorGuid;
  ULONG               NameLength;
  CHAR16              VariableName[ANYSIZE_ARRAY];
} EFI_GET_NEXT_VARIABLE_NAME_OUT, *PEFI_GET_NEXT_VARIABLE_NAME_OUT;