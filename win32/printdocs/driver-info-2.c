typedef struct _DRIVER_INFO_2 {
  DWORD  cVersion;
  LPTSTR pName;
  LPTSTR pEnvironment;
  LPTSTR pDriverPath;
  LPTSTR pDataFile;
  LPTSTR pConfigFile;
} DRIVER_INFO_2, *PDRIVER_INFO_2;