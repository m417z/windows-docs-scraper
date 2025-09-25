typedef struct _WTSCONFIGINFOA {
  ULONG version;
  ULONG fConnectClientDrivesAtLogon;
  ULONG fConnectPrinterAtLogon;
  ULONG fDisablePrinterRedirection;
  ULONG fDisableDefaultMainClientPrinter;
  ULONG ShadowSettings;
  CHAR  LogonUserName[USERNAME_LENGTH + 1];
  CHAR  LogonDomain[DOMAIN_LENGTH + 1];
  CHAR  WorkDirectory[MAX_PATH + 1];
  CHAR  InitialProgram[MAX_PATH + 1];
  CHAR  ApplicationName[MAX_PATH + 1];
} WTSCONFIGINFOA, *PWTSCONFIGINFOA;