typedef struct tagNETCON_PROPERTIES {
  GUID             guidId;
  LPWSTR           pszwName;
  LPWSTR           pszwDeviceName;
  NETCON_STATUS    Status;
  NETCON_MEDIATYPE MediaType;
  DWORD            dwCharacter;
  CLSID            clsidThisObject;
  CLSID            clsidUiObject;
} NETCON_PROPERTIES;