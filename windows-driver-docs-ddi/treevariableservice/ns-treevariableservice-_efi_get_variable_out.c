typedef struct _EFI_GET_VARIABLE_OUT {
  EFI_VARIABLE_STATUS EfiStatus;
  ULONG               Attributes;
  SIZE_T              DataSize;
  BYTE                Data[ANYSIZE_ARRAY];
} EFI_GET_VARIABLE_OUT, *PEFI_GET_VARIABLE_OUT;