struct RILSUBSCRIBERINFO {
  DWORD                    cbSize;
  DWORD                    dwParams;
  RILADDRESS               raAddress;
  WCHAR                    wszDescription[MAXLENGTH_DESCRIPTION];
  RILSUBSCRIBERINFOSERVICE dwService;
};