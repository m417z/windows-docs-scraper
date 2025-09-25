typedef struct _DRIVER_UPGRADE_INFO_2 {
  LPTSTR pPrinterName;
  LPTSTR pOldDriverDirectory;
  DWORD  cVersion;
  LPTSTR pName;
  LPTSTR pEnvironment;
  LPTSTR pDriverPath;
  LPTSTR pDataFile;
  LPTSTR pConfigFile;
  LPTSTR pHelpFile;
  LPTSTR pDependentFiles;
  LPTSTR pMonitorName;
  LPTSTR pDefaultDataType;
  LPTSTR pszzPreviousNames;
} DRIVER_UPGRADE_INFO_2, *PDRIVER_UPGRADE_INFO_2;