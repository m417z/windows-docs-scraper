typedef struct RILHIDECONNECTEDIDSETTINGS {
  DWORD                        cbSize;
  DWORD                        dwParams;
  DWORD                        dwExecutor;
  RILSERVICESETTINGSSTATUS     dwStatus;
  RILSERVICEPROVISIONINGSTATUS dwProvisioning;
} RILHIDECONNECTEDIDSETTINGS, *LPRILHIDECONNECTEDIDSETTINGS;