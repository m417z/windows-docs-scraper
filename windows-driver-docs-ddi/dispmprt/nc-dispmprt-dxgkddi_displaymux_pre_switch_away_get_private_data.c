DXGKDDI_DISPLAYMUX_PRE_SWITCH_AWAY_GET_PRIVATE_DATA DxgkddiDisplaymuxPreSwitchAwayGetPrivateData;

NTSTATUS DxgkddiDisplaymuxPreSwitchAwayGetPrivateData(
  PVOID DriverContext,
  ULONG VidPnTargetId,
  ULONG SwitchPrivateDataSize,
  PVOID pSwitchPrivateDataBuffer,
  GUID *pSwitchPrivateDataGUID
)
{...}