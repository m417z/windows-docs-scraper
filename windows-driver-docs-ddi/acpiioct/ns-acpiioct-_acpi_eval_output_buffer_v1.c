typedef struct _ACPI_EVAL_OUTPUT_BUFFER_V1 {
  ULONG                   Signature;
  ULONG                   Length;
  ULONG                   Count;
  ACPI_METHOD_ARGUMENT_V1 Argument[ANYSIZE_ARRAY];
} ACPI_EVAL_OUTPUT_BUFFER_V1, ACPI_EVAL_OUTPUT_BUFFER, *PACPI_EVAL_OUTPUT_BUFFER;