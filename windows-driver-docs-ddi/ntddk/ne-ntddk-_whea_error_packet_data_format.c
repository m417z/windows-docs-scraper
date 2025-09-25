typedef enum _WHEA_ERROR_PACKET_DATA_FORMAT {
  WheaDataFormatIPFSalRecord,
  WheaDataFormatXPFMCA,
  WheaDataFormatMemory,
  WheaDataFormatPCIExpress,
  WheaDataFormatNMIPort,
  WheaDataFormatPCIXBus,
  WheaDataFormatPCIXDevice,
  WheaDataFormatGeneric,
  WheaDataFormatMax
} WHEA_ERROR_PACKET_DATA_FORMAT, *PWHEA_ERROR_PACKET_DATA_FORMAT;