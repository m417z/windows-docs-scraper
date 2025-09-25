EVT_VHF_ASYNC_OPERATION EvtVhfAsyncOperation;

VOID EvtVhfAsyncOperation(
  [in]           PVOID VhfClientContext,
  [in]           VHFOPERATIONHANDLE VhfOperationHandle,
  [in, optional] PVOID VhfOperationContext,
  [in]           PHID_XFER_PACKET HidTransferPacket
)
{...}