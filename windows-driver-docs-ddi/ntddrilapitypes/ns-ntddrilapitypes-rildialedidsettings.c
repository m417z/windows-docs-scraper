typedef struct RILDIALEDIDSETTINGS {
  DWORD                        cbSize;
  DWORD                        dwParams;
  DWORD                        dwExecutor;
  RILSERVICESETTINGSSTATUS     dwStatus;
  RILSERVICEPROVISIONINGSTATUS dwProvisioning;
} RILDIALEDIDSETTINGS, *LPRILDIALEDIDSETTINGS;