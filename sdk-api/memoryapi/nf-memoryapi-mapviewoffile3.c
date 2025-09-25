PVOID MapViewOfFile3(
  [in]                HANDLE                 FileMapping,
  [in]                HANDLE                 Process,
  [in, optional]      PVOID                  BaseAddress,
  [in]                ULONG64                Offset,
  [in]                SIZE_T                 ViewSize,
  [in]                ULONG                  AllocationType,
  [in]                ULONG                  PageProtection,
  [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
  [in]                ULONG                  ParameterCount
);