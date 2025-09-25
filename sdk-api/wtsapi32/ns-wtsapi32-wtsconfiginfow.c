typedef struct _WTSCONFIGINFOW {
  ULONG version;
  ULONG fConnectClientDrivesAtLogon;
  ULONG fConnectPrinterAtLogon;
  ULONG fDisablePrinterRedirection;
  ULONG fDisableDefaultMainClientPrinter;
  ULONG ShadowSettings;
  WCHAR LogonUserName[USERNAME_LENGTH + 1];
  WCHAR LogonDomain[DOMAIN_LENGTH + 1];
  WCHAR WorkDirectory[MAX_PATH + 1];
  WCHAR InitialProgram[MAX_PATH + 1];
  WCHAR ApplicationName[MAX_PATH + 1];
} WTSCONFIGINFOW, *PWTSCONFIGINFOW;