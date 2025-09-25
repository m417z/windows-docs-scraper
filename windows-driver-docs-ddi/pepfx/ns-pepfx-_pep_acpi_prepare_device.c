typedef struct _PEP_ACPI_PREPARE_DEVICE {
  [in]  PCUNICODE_STRING AcpiDeviceName;
  [in]  ULONG            InputFlags;
  [out] BOOLEAN          DeviceAccepted;
  [out] ULONG            OutputFlags;
} PEP_ACPI_PREPARE_DEVICE, *PPEP_ACPI_PREPARE_DEVICE;