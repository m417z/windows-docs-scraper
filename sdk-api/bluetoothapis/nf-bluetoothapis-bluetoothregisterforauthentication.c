DWORD BluetoothRegisterForAuthentication(
  const BLUETOOTH_DEVICE_INFO            *pbtdi,
  HBLUETOOTH_AUTHENTICATION_REGISTRATION *phRegHandle,
  PFN_AUTHENTICATION_CALLBACK            pfnCallback,
  PVOID                                  pvParam
);