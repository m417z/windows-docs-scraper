typedef struct _PEP_ACPI_QUERY_DEVICE_CONTROL_RESOURCES {
  [in]      PEPHANDLE            DeviceHandle;
  [in]      ULONG                RequestFlags;
  [out]     NTSTATUS             Status;
  [in, out] SIZE_T               BiosResourcesSize;
            ACPI_METHOD_ARGUMENT BiosResources[ANYSIZE_ARRAY];
} PEP_ACPI_QUERY_DEVICE_CONTROL_RESOURCES, *PPEP_ACPI_QUERY_DEVICE_CONTROL_RESOURCES;