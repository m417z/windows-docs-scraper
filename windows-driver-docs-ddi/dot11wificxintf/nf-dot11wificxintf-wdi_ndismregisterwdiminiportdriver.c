NDIS_STATUS Wdi_NdisMRegisterWdiMiniportDriver(
  PDRIVER_OBJECT                            DriverObject,
  PUNICODE_STRING                           RegistryPath,
  NDIS_HANDLE                               MiniportDriverContext,
  PNDIS_MINIPORT_DRIVER_CHARACTERISTICS     MiniportDriverCharacteristics,
  PNDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS MiniportWdiCharacteristics,
  PNDIS_HANDLE                              NdisMiniportDriverHandle
);