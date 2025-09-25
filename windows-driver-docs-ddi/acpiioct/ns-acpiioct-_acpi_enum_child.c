typedef struct _ACPI_ENUM_CHILD {
  ULONG Flags;
  ULONG NameLength;
  CHAR  Name[ANYSIZE_ARRAY];
} ACPI_ENUM_CHILD;