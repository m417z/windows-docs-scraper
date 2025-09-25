typedef struct _WHEA_PCIE_CORRECTABLE_ERROR_DEVICES {
  WHEA_PCIE_CORRECTABLE_ERROR_DEVICES_VALIDBITS ValidBits;
  WHEA_PCIE_ADDRESS                             Address;
  UINT32                                        Mask;
  UINT32                                        CorrectableErrorCount[WHEA_PCIE_CORRECTABLE_ERROR_SECTION_COUNT_SIZE];
} WHEA_PCIE_CORRECTABLE_ERROR_DEVICES, *PWHEA_PCIE_CORRECTABLE_ERROR_DEVICES;