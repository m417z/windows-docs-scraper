EVT_HIDSPICX_NOTIFY_POWERDOWN EvtHidspicxNotifyPowerdown;

NTSTATUS EvtHidspicxNotifyPowerdown(
  WDFDEVICE Device,
  BOOLEAN ArmForWake
)
{...}