typedef struct _BLUETOOTH_SELECT_DEVICE_PARAMS {
  DWORD                  dwSize;
  ULONG                  cNumOfClasses;
  BLUETOOTH_COD_PAIRS    *prgClassOfDevices;
  LPWSTR                 pszInfo;
  HWND                   hwndParent;
  BOOL                   fForceAuthentication;
  BOOL                   fShowAuthenticated;
  BOOL                   fShowRemembered;
  BOOL                   fShowUnknown;
  BOOL                   fAddNewDeviceWizard;
  BOOL                   fSkipServicesPage;
  PFN_DEVICE_CALLBACK    pfnDeviceCallback;
  LPVOID                 pvParam;
  DWORD                  cNumDevices;
  PBLUETOOTH_DEVICE_INFO pDevices;
} BLUETOOTH_SELECT_DEVICE_PARAMS;