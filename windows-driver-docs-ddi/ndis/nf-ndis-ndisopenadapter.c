VOID NdisOpenAdapter(
  [out]          PNDIS_STATUS Status,
  [out]          PNDIS_STATUS OpenErrorStatus,
  [out]          PNDIS_HANDLE NdisBindingHandle,
  [out]          PUINT        SelectedMediumIndex,
  [in]           PNDIS_MEDIUM MediumArray,
  [in]           UINT         MediumArraySize,
  [in]           NDIS_HANDLE  NdisProtocolHandle,
  [in]           NDIS_HANDLE  ProtocolBindingContext,
  [in]           PNDIS_STRING AdapterName,
  [in]           UINT         OpenOptions,
  [in, optional] PSTRING      AddressingInformation
);