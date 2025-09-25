EVT_MBB_DEVICE_SEND_DEVICE_SERVICE_SESSION_DATA EvtMbbDeviceSendDeviceServiceSessionData;

VOID EvtMbbDeviceSendDeviceServiceSessionData(
  WDFDEVICE Device,
  DSS_SESSION_ID SessionId,
  WDFMEMORY Data
)
{...}