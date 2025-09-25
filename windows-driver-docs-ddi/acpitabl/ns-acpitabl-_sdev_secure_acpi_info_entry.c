typedef struct _SDEV_SECURE_ACPI_INFO_ENTRY {
  SDEV_ENTRY_HEADER Header;
  USHORT            IdentifierOffset;
  USHORT            IdentifierLength;
  USHORT            VendorInfoOffset;
  USHORT            VendorInfoLength;
  USHORT            SecureResourcesOffset;
  USHORT            SecureResourcesLength;
} SDEV_SECURE_ACPI_INFO_ENTRY, *PSDEV_SECURE_ACPI_INFO_ENTRY;