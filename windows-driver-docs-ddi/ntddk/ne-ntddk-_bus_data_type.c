typedef enum _BUS_DATA_TYPE {
  ConfigurationSpaceUndefined,
  Cmos,
  EisaConfiguration,
  Pos,
  CbusConfiguration,
  PCIConfiguration,
  VMEConfiguration,
  NuBusConfiguration,
  PCMCIAConfiguration,
  MPIConfiguration,
  MPSAConfiguration,
  PNPISAConfiguration,
  SgiInternalConfiguration,
  MaximumBusDataType
} BUS_DATA_TYPE, *PBUS_DATA_TYPE;