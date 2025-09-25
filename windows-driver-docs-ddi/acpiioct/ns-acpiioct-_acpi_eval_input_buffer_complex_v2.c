typedef struct _ACPI_EVAL_INPUT_BUFFER_COMPLEX_V2 {
  ULONG                   Signature;
  union {
    UCHAR MethodName[4];
    ULONG MethodNameAsUlong;
  } DUMMYUNIONNAME;
  ULONG                   Size;
  ULONG                   ArgumentCount;
  ACPI_METHOD_ARGUMENT_V2 Argument[ANYSIZE_ARRAY];
} ACPI_EVAL_INPUT_BUFFER_COMPLEX_V2, *PACPI_EVAL_INPUT_BUFFER_COMPLEX_V2;