typedef struct __WMDMID {
  UINT  cbSize;
  DWORD dwVendorID;
  BYTE  pID[WMDMID_LENGTH];
  UINT  SerialNumberLength;
} WMDMID, *PWMDMID;