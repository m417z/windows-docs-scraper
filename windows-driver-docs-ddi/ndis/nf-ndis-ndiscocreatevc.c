NDIS_STATUS NdisCoCreateVc(
  [in]           NDIS_HANDLE  NdisBindingHandle,
  [in, optional] NDIS_HANDLE  NdisAfHandle,
  [in]           NDIS_HANDLE  ProtocolVcContext,
  [in, out]      PNDIS_HANDLE NdisVcHandle
);