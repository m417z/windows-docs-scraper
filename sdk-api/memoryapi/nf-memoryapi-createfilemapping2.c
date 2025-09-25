HANDLE CreateFileMapping2(
  HANDLE                 File,
  SECURITY_ATTRIBUTES    *SecurityAttributes,
  ULONG                  DesiredAccess,
  ULONG                  PageProtection,
  ULONG                  AllocationAttributes,
  ULONG64                MaximumSize,
  PCWSTR                 Name,
  MEM_EXTENDED_PARAMETER *ExtendedParameters,
  ULONG                  ParameterCount
);