EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED EvtWdfChildListDeviceReenumerated;

BOOLEAN EvtWdfChildListDeviceReenumerated(
  [in]  WDFCHILDLIST ChildList,
  [in]  WDFDEVICE OldDevice,
  [in]  PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER OldAddressDescription,
  [out] PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER NewAddressDescription
)
{...}