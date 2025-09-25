typedef struct RILCALLINFO_V2 {
  DWORD                          cbSize;
  DWORD                          dwParams;
  DWORD                          dwExecutor;
  DWORD                          dwID;
  RILCALLINFODIRECTION           dwDirection;
  RILCALLINFOSTATUS              dwStatus;
  RILCALLTYPE                    dwType;
  RILCALLINFOMULTIPARTY          dwMultiparty;
  RILADDRESS                     raAddress;
  RILSUBADDRESS                  rsaSubAddress;
  WCHAR                          wszDescription[256];
  RILREMOTEPARTYINFOVALUE        dwNumberPresentationIndicator;
  RILREMOTEPARTYINFOVALUE        dwNamePresentationIndicator;
  DWORD                          dwFlags;
  RILCALLINFODISCONNECTINITIATOR dwDisconnectInitiator;
  RILCALLINFODISCONNECTREASON    dwDisconnectReason;
  RILCALLDISCONNECTDETAILS       stDisconnectDetails;
} RILCALLINFO_V2, *LPRILCALLINFO_V2;