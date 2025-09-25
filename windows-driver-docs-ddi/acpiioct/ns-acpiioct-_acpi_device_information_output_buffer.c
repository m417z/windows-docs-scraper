typedef struct _ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER {
  ULONG  Signature;
  USHORT Size;
  UCHAR  Revision;
  UCHAR  Reserved0;
  USHORT VendorIdStringOffset;
  USHORT VendorStringLength;
  USHORT DeviceIdStringOffset;
  USHORT SubSystemIdStringOffset;
  USHORT SubSystemStringLength;
  USHORT SubDeviceIdStringOffset;
  USHORT InstanceIdLength;
  USHORT InstanceIdOffset;
  USHORT BaseClassCode;
  USHORT HardwareRevision;
  UCHAR  ProgrammingInterface;
  UCHAR  Reserved1;
  USHORT SubClassCode;
} ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER, *PACPI_DEVICE_INFORMATION_OUTPUT_BUFFER;