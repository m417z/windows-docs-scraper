EVT_SERCX2_PURGE_FIFOS EvtSercx2PurgeFifos;

VOID EvtSercx2PurgeFifos(
  [in] WDFDEVICE Device,
  [in] BOOLEAN PurgeRxFifo,
  [in] BOOLEAN PurgeTxFifo
)
{...}