typedef struct _PEP_ACPI_QUERY_OBJECT_INFORMATION {
  [in]  PEPHANDLE            DeviceHandle;
  [in]  PEP_ACPI_OBJECT_NAME Name;
  [in]  PEP_ACPI_OBJECT_TYPE Type;
  [in]  ULONG                ObjectFlags;
  union {
    struct {
      ULONG InputArgumentCount;
      ULONG OutputArgumentCount;
    } MethodObject;
  } DUMMYUNIONNAME;
} PEP_ACPI_QUERY_OBJECT_INFORMATION, *PPEP_ACPI_QUERY_OBJECT_INFORMATION;