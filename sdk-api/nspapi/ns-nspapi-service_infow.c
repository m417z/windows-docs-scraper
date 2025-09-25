typedef struct _SERVICE_INFOW {
  LPGUID              lpServiceType;
  LPWSTR              lpServiceName;
  LPWSTR              lpComment;
  LPWSTR              lpLocale;
  DWORD               dwDisplayHint;
  DWORD               dwVersion;
  DWORD               dwTime;
  LPWSTR              lpMachineName;
  LPSERVICE_ADDRESSES lpServiceAddress;
  BLOB                ServiceSpecificInfo;
} SERVICE_INFOW, *PSERVICE_INFOW, *LPSERVICE_INFOW;