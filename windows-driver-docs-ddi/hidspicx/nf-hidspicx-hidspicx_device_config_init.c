VOID HIDSPICX_DEVICE_CONFIG_INIT(
  PHIDSPICX_DEVICE_CONFIG       DeviceConfig,
  PFN_HIDSPICX_RESETDEVICE      EvtResetDevice,
  PFN_HIDSPICX_NOTIFY_POWERDOWN EvtNotifyPowerDown,
  WDFQUEUE                      InputReportQueue,
  WDFQUEUE                      OutputReportQueue
);