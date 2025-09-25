typedef struct RILCALLERIDSETTINGS {
  DWORD                        cbSize;
  DWORD                        dwParams;
  DWORD                        dwExecutor;
  RILSERVICESETTINGSSTATUS     dwStatus;
  RILSERVICEPROVISIONINGSTATUS dwProvisioning;
} RILCALLERIDSETTINGS, *LPRILCALLERIDSETTINGS;