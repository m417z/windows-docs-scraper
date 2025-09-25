DWORD BluetoothEnumerateInstalledServices(
  HANDLE                      hRadio,
  const BLUETOOTH_DEVICE_INFO *pbtdi,
  DWORD                       *pcServiceInout,
  GUID                        *pGuidServices
);