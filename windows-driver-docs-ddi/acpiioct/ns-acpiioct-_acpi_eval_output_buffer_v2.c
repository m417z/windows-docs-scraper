typedef struct _ACPI_EVAL_OUTPUT_BUFFER_V2 {
  ULONG                   Signature;
  ULONG                   Length;
  ULONG                   Count;
  ACPI_METHOD_ARGUMENT_V2 Argument[ANYSIZE_ARRAY];
} ACPI_EVAL_OUTPUT_BUFFER_V2;