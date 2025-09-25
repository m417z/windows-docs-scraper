DWORD BluetoothRegisterForAuthenticationEx(
  [in, optional] const BLUETOOTH_DEVICE_INFO            *pbtdiIn,
  [out]          HBLUETOOTH_AUTHENTICATION_REGISTRATION *phRegHandleOut,
  [in, optional] PFN_AUTHENTICATION_CALLBACK_EX         pfnCallbackIn,
  [in, optional] PVOID                                  pvParam
);