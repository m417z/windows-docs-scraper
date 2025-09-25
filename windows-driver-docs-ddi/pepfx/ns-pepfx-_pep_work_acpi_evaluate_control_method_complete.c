typedef struct _PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE {
  POHANDLE              DeviceHandle;
  ULONG                 CompletionFlags;
  NTSTATUS              MethodStatus;
  PVOID                 CompletionContext;
  SIZE_T                OutputArgumentSize;
  PACPI_METHOD_ARGUMENT OutputArguments;
} PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE, *PPEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE;