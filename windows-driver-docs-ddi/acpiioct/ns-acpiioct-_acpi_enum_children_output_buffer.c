typedef struct _ACPI_ENUM_CHILDREN_OUTPUT_BUFFER {
  ULONG           Signature;
  ULONG           NumberOfChildren;
  ACPI_ENUM_CHILD Children[ANYSIZE_ARRAY];
} ACPI_ENUM_CHILDREN_OUTPUT_BUFFER;