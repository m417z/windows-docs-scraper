DWORD BluetoothSetLocalServiceInfo(
  [in, optional] HANDLE                             hRadioIn,
  [in]           const GUID                         *pClassGuid,
  [in]           ULONG                              ulInstance,
  [in]           const BLUETOOTH_LOCAL_SERVICE_INFO *pServiceInfoIn
);