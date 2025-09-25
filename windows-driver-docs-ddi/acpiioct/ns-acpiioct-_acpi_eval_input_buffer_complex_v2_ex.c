typedef struct _ACPI_EVAL_INPUT_BUFFER_COMPLEX_V2_EX {
  ULONG                   Signature;
  CHAR                    MethodName[256];
  ULONG                   Size;
  ULONG                   ArgumentCount;
  ACPI_METHOD_ARGUMENT_V2 Argument[ANYSIZE_ARRAY];
} ACPI_EVAL_INPUT_BUFFER_COMPLEX_V2_EX, *PACPI_EVAL_INPUT_BUFFER_COMPLEX_V2_EX;