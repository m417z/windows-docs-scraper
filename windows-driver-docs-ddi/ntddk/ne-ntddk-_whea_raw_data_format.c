typedef enum _WHEA_RAW_DATA_FORMAT {
  WheaRawDataFormatIPFSalRecord,
  WheaRawDataFormatIA32MCA,
  WheaRawDataFormatIntel64MCA,
  WheaRawDataFormatAMD64MCA,
  WheaRawDataFormatMemory,
  WheaRawDataFormatPCIExpress,
  WheaRawDataFormatNMIPort,
  WheaRawDataFormatPCIXBus,
  WheaRawDataFormatPCIXDevice,
  WheaRawDataFormatGeneric,
  WheaRawDataFormatMax
} WHEA_RAW_DATA_FORMAT, *PWHEA_RAW_DATA_FORMAT;