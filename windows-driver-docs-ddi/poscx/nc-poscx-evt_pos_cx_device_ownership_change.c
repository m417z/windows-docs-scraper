EVT_POS_CX_DEVICE_OWNERSHIP_CHANGE EvtPosCxDeviceOwnershipChange;

VOID EvtPosCxDeviceOwnershipChange(
  [in]           WDFDEVICE device,
  [in, optional] WDFFILEOBJECT oldOwnerFileObj,
  [in, optional] WDFFILEOBJECT newOwnerFileObj
)
{...}