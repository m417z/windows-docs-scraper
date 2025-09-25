EVT_VMB_CHANNEL_PNP_FAILURE EvtVmbChannelPnpFailure;

VOID EvtVmbChannelPnpFailure(
  [in] VMBCHANNEL Channel,
  [in] NTSTATUS FailureStatus
)
{...}