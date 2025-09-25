typedef struct _HIDSPICX_DEVICE_CONFIG {
  ULONG                         Size;
  PFN_HIDSPICX_RESETDEVICE      EvtResetDevice;
  PFN_HIDSPICX_NOTIFY_POWERDOWN EvtNotifyPowerDown;
  WDFQUEUE                      InputReportQueue;
  WDFQUEUE                      OutputReportQueue;
  ULONG                         NumberOfInputReportRequestsToPend;
  ULONG                         Reserved;
} HIDSPICX_DEVICE_CONFIG, *PHIDSPICX_DEVICE_CONFIG;