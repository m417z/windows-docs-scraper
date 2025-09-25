NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisMRegisterWdiMiniportDriver(
  [in]           DRIVER_OBJECT                            *DriverObject,
  [in]           PCUNICODE_STRING                         RegistryPath,
  [in, optional] NDIS_MINIPORT_DRIVER_CONTEXT             NdisDriverContext,
  [in]           NDIS_MINIPORT_DRIVER_CHARACTERISTICS     *MiniportDriverCharacteristics,
  [in]           NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS *MiniportWdiCharacteristics,
  [out]          NDIS_MINIPORT_DRIVER_HANDLE              *NdisMiniportDriverHandle
);