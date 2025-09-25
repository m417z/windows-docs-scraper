VOID NdisCmMakeCallComplete(
  [in]           NDIS_STATUS         Status,
  [in]           NDIS_HANDLE         NdisVcHandle,
  [in, optional] NDIS_HANDLE         NdisPartyHandle,
  [in, optional] NDIS_HANDLE         CallMgrPartyContext,
  [in]           PCO_CALL_PARAMETERS CallParameters
);