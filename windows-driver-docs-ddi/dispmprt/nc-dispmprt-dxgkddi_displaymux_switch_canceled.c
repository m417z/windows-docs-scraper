DXGKDDI_DISPLAYMUX_SWITCH_CANCELED DxgkddiDisplaymuxSwitchCanceled;

NTSTATUS DxgkddiDisplaymuxSwitchCanceled(
  PVOID DriverContext,
  ULONG VidPnTargetId,
  BOOLEAN MuxSwitchedToTarget
)
{...}