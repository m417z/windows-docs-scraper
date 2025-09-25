typedef struct _EFI_QUERY_VARIABLE_INFO_OUT {
  EFI_VARIABLE_STATUS EfiStatus;
  ULONGLONG           MaximumVariableStorageSize;
  ULONGLONG           RemainingVariableStorageSize;
  ULONGLONG           MaximumVariableSize;
} EFI_QUERY_VARIABLE_INFO_OUT, *PEFI_QUERY_VARIABLE_INFO_OUT;