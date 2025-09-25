typedef struct _ACPI_EVAL_INPUT_BUFFER_V2 {
  ULONG Signature;
  union {
    UCHAR MethodName[4];
    ULONG MethodNameAsUlong;
  } DUMMYUNIONNAME;
} ACPI_EVAL_INPUT_BUFFER_V2, *PACPI_EVAL_INPUT_BUFFER_V2;