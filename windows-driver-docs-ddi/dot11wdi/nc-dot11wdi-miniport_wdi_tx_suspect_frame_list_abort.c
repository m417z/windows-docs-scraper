MINIPORT_WDI_TX_SUSPECT_FRAME_LIST_ABORT MiniportWdiTxSuspectFrameListAbort;

void MiniportWdiTxSuspectFrameListAbort(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  UINT64 SuspectFrameContext,
  UINT16 NumSuspectFrames,
  PNET_BUFFER_LIST *SuspectFrameList
)
{...}