PVOID VirtualAlloc2(
  [in, optional]      HANDLE                 Process,
  [in, optional]      PVOID                  BaseAddress,
  [in]                SIZE_T                 Size,
  [in]                ULONG                  AllocationType,
  [in]                ULONG                  PageProtection,
  [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
  [in]                ULONG                  ParameterCount
);