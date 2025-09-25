NDIS_STATUS NdisRegisterProtocolDriver(
  [in, optional] NDIS_HANDLE                           ProtocolDriverContext,
  [in]           PNDIS_PROTOCOL_DRIVER_CHARACTERISTICS ProtocolCharacteristics,
  [out]          PNDIS_HANDLE                          NdisProtocolHandle
);