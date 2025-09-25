typedef struct _ACPI_METHOD_ARGUMENT_V2 {
  USHORT Type;
  ULONG  DataLength;
  union {
    ULONG Argument;
    UCHAR Data[ANYSIZE_ARRAY];
  } DUMMYUNIONNAME;
} ACPI_METHOD_ARGUMENT_V2;