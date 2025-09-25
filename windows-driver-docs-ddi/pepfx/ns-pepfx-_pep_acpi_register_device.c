typedef struct _PEP_ACPI_REGISTER_DEVICE {
  [in]  PCUNICODE_STRING AcpiDeviceName;
  [in]  ULONG            InputFlags;
  [in]  POHANDLE         KernelHandle;
  [out] PEPHANDLE        DeviceHandle;
  [out] ULONG            OutputFlags;
} PEP_ACPI_REGISTER_DEVICE, *PPEP_ACPI_REGISTER_DEVICE;