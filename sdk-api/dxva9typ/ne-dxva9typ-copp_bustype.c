typedef enum _COPP_BusType {
  COPP_BusType_Unknown = 0,
  COPP_BusType_PCI = 1,
  COPP_BusType_PCIX = 2,
  COPP_BusType_PCIExpress = 3,
  COPP_BusType_AGP = 4,
  COPP_BusType_Integrated = 0x80000000,
  COPP_BusType_ForceDWORD
} COPP_BusType;