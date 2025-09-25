NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisMRegisterWdiMiniportDriver(
  DRIVER_OBJECT                            *DriverObject,
  PCUNICODE_STRING                         RegistryPath,
  NDIS_MINIPORT_DRIVER_CONTEXT             NdisDriverContext,
  NDIS_MINIPORT_DRIVER_CHARACTERISTICS     *MiniportDriverCharacteristics,
  NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS *MiniportWdiCharacteristics,
  NDIS_MINIPORT_DRIVER_HANDLE              *NdisMiniportDriverHandle
);