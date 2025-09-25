typedef struct _SYSENV_VARIABLE {
  GUID  VendorGuid;
  ULONG VariableNameLength;
  WCHAR VariableName[ANYSIZE_ARRAY];
} SYSENV_VARIABLE, *PSYSENV_VARIABLE;