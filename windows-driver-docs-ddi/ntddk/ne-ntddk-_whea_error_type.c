typedef enum _WHEA_ERROR_TYPE {
  WheaErrTypeProcessor,
  WheaErrTypeMemory,
  WheaErrTypePCIExpress,
  WheaErrTypeNMI,
  WheaErrTypePCIXBus,
  WheaErrTypePCIXDevice,
  WheaErrTypeGeneric,
  WheaErrTypePmem
} WHEA_ERROR_TYPE, *PWHEA_ERROR_TYPE;