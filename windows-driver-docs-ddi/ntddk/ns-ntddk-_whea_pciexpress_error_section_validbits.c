typedef union _WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS {
  struct {
    ULONGLONG PortType : 1;
    ULONGLONG Version : 1;
    ULONGLONG CommandStatus : 1;
    ULONGLONG DeviceId : 1;
    ULONGLONG DeviceSerialNumber : 1;
    ULONGLONG BridgeControlStatus : 1;
    ULONGLONG ExpressCapability : 1;
    ULONGLONG AerInfo : 1;
    ULONGLONG Reserved : 56;
  } DUMMYSTRUCTNAME;
  ULONGLONG ValidBits;
} WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS, *PWHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS;