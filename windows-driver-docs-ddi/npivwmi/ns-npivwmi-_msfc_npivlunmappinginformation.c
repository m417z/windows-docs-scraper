typedef struct _MSFC_NPIVLUNMappingInformation {
  UCHAR WWPNVirtualPort[8];
  UCHAR WWPNPhysicalPort[8];
  UCHAR OSBus;
  UCHAR OSTarget;
  UCHAR OSLUN;
} MSFC_NPIVLUNMappingInformation, *PMSFC_NPIVLUNMappingInformation;