typedef struct _PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES {
  [in]  PEPHANDLE         DeviceHandle;
  [in]  ULONG             RequestFlags;
  [out] NTSTATUS          Status;
        SIZE_T            TranslatedResourcesSize;
  [in]  PCM_RESOURCE_LIST TranslatedResources;
} PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES, *PPEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES;