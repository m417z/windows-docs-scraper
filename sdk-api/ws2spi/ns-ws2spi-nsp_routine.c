typedef struct _NSP_ROUTINE {
  DWORD                    cbSize;
  DWORD                    dwMajorVersion;
  DWORD                    dwMinorVersion;
  LPNSPCLEANUP             NSPCleanup;
  LPNSPLOOKUPSERVICEBEGIN  NSPLookupServiceBegin;
  LPNSPLOOKUPSERVICENEXT   NSPLookupServiceNext;
  LPNSPLOOKUPSERVICEEND    NSPLookupServiceEnd;
  LPNSPSETSERVICE          NSPSetService;
  LPNSPINSTALLSERVICECLASS NSPInstallServiceClass;
  LPNSPREMOVESERVICECLASS  NSPRemoveServiceClass;
  LPNSPGETSERVICECLASSINFO NSPGetServiceClassInfo;
  LPNSPIOCTL               NSPIoctl;
} NSP_ROUTINE, *LPNSP_ROUTINE;