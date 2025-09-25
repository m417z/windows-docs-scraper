DXGKDDI_DISPLAYMUX_POST_SWITCH_TO_PHASE1 DxgkddiDisplaymuxPostSwitchToPhase1;

NTSTATUS DxgkddiDisplaymuxPostSwitchToPhase1(
  PVOID DriverContext,
  ULONG VidPnTargetId,
  ULONG SwitchPrivateDataSize,
  PVOID pSwitchPrivateDataBuffer,
  GUID *pSwitchPrivateDataGUID
)
{...}