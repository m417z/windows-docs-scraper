NDIS_STATUS NdisMRegisterMiniportDriver(
  [in]           PDRIVER_OBJECT                        DriverObject,
  [in]           PUNICODE_STRING                       RegistryPath,
  [in, optional] NDIS_HANDLE                           MiniportDriverContext,
  [in]           PNDIS_MINIPORT_DRIVER_CHARACTERISTICS MiniportDriverCharacteristics,
  [out]          PNDIS_HANDLE                          NdisMiniportDriverHandle
);