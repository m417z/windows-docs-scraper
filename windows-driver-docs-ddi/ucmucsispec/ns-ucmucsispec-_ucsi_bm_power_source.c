typedef union _UCSI_BM_POWER_SOURCE {
  UINT8  AsUInt8;
  struct {
    UINT8 AcSupply : 1;
    UINT8 Other : 1;
    UINT8 UsesVBus : 1;
  };
} UCSI_BM_POWER_SOURCE, *PUCSI_BM_POWER_SOURCE;