EVT_WDF_DEVICE_FILE_CREATE EvtWdfDeviceFileCreate;

VOID EvtWdfDeviceFileCreate(
  [in] WDFDEVICE Device,
  [in] WDFREQUEST Request,
  [in] WDFFILEOBJECT FileObject
)
{...}