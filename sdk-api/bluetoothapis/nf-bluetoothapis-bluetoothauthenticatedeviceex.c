DWORD BluetoothAuthenticateDeviceEx(
  [in, optional] HWND                        hwndParentIn,
  [in, optional] HANDLE                      hRadioIn,
  [in, out]      BLUETOOTH_DEVICE_INFO       *pbtdiInout,
  [in, optional] PBLUETOOTH_OOB_DATA_INFO    pbtOobData,
  [in]           AUTHENTICATION_REQUIREMENTS authenticationRequirement
);