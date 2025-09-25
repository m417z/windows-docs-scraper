typedef struct _PEP_ACPI_ABANDON_DEVICE {
  [in]  PCUNICODE_STRING AcpiDeviceName;
  [out] BOOLEAN          DeviceAccepted;
} PEP_ACPI_ABANDON_DEVICE, *PPEP_ACPI_ABANDON_DEVICE;