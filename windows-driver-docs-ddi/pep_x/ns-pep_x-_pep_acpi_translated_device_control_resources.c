typedef struct _PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES {
  PEPHANDLE         DeviceHandle;
  ULONG             RequestFlags;
  NTSTATUS          Status;
  SIZE_T            TranslatedResourcesSize;
  PCM_RESOURCE_LIST TranslatedResources;
} PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES, *PPEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES;