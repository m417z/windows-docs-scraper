DWORD BluetoothSetServiceState(
  HANDLE                      hRadio,
  const BLUETOOTH_DEVICE_INFO *pbtdi,
  const GUID                  *pGuidService,
  DWORD                       dwServiceFlags
);