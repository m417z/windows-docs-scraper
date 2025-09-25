typedef struct _WHEA_PCIEXPRESS_ERROR_SECTION {
  WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS ValidBits;
  WHEA_PCIEXPRESS_DEVICE_TYPE             PortType;
  WHEA_PCIEXPRESS_VERSION                 Version;
  WHEA_PCIEXPRESS_COMMAND_STATUS          CommandStatus;
  ULONG                                   Reserved;
  WHEA_PCIEXPRESS_DEVICE_ID               DeviceId;
  ULONGLONG                               DeviceSerialNumber;
  WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS   BridgeControlStatus;
  UCHAR                                   ExpressCapability[60];
  UCHAR                                   AerInfo[96];
} WHEA_PCIEXPRESS_ERROR_SECTION, *PWHEA_PCIEXPRESS_ERROR_SECTION;