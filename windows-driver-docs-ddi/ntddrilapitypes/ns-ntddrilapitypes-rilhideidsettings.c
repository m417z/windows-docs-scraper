typedef struct RILHIDEIDSETTINGS {
  DWORD                        cbSize;
  DWORD                        dwParams;
  DWORD                        dwExecutor;
  RILSERVICESETTINGSSTATUS     dwStatus;
  RILSERVICEPROVISIONINGSTATUS dwProvisioning;
} RILHIDEIDSETTINGS, *LPRILHIDEIDSETTINGS;