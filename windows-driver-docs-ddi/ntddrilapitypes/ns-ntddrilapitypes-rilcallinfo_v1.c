typedef struct RILCALLINFO_V1 {
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
  BOOL                           fAlienCall;
  RILCALLINFODISCONNECTINITIATOR dwDisconnectInitiator;
  RILCALLINFODISCONNECTREASON    dwDisconnectReason;
  RILCALLDISCONNECTDETAILS       stDisconnectDetails;
} RILCALLINFO_V1, *LPRILCALLINFO_V1;