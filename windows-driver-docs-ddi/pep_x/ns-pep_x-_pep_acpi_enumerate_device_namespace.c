typedef struct _PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE {
  PEPHANDLE                      DeviceHandle;
  ULONG                          RequestFlags;
  NTSTATUS                       Status;
  ULONG                          ObjectCount;
  SIZE_T                         ObjectBufferSize;
  PEP_ACPI_OBJECT_NAME_WITH_TYPE Objects[ANYSIZE_ARRAY];
} PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE, *PPEP_ACPI_ENUMERATE_DEVICE_NAMESPACE;