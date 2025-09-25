typedef struct _ADMINISTRATOR_POWER_POLICY {
  SYSTEM_POWER_STATE MinSleep;
  SYSTEM_POWER_STATE MaxSleep;
  DWORD              MinVideoTimeout;
  DWORD              MaxVideoTimeout;
  DWORD              MinSpindownTimeout;
  DWORD              MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY, *PADMINISTRATOR_POWER_POLICY;