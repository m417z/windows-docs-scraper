typedef struct _PEP_ACPI_EVALUATE_CONTROL_METHOD {
  PEPHANDLE             DeviceHandle;
  ULONG                 RequestFlags;
  union {
    ULONG       MethodName;
    ANSI_STRING MethodNameString;
  };
  NTSTATUS              MethodStatus;
  PVOID                 CompletionContext;
  ULONG                 InputArgumentCount;
  SIZE_T                InputArgumentSize;
  PACPI_METHOD_ARGUMENT InputArguments;
  ULONG                 OutputArgumentCount;
  SIZE_T                OutputArgumentSize;
  PACPI_METHOD_ARGUMENT OutputArguments;
} PEP_ACPI_EVALUATE_CONTROL_METHOD, *PPEP_ACPI_EVALUATE_CONTROL_METHOD;