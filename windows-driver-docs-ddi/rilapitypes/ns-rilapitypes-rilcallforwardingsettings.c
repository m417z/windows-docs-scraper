typedef struct RILCALLFORWARDINGSETTINGS {
  DWORD                    cbSize;
  DWORD                    dwParams;
  RILSERVICESETTINGSSTATUS dwStatus;
  DWORD                    dwInfoClasses;
  RILADDRESS               raAddress;
  RILSUBADDRESS            rsaSubAddress;
  DWORD                    dwDelayTime;
} RILCALLFORWARDINGSETTINGS, *LPRILCALLFORWARDINGSETTINGS;