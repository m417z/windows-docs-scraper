typedef struct RILREQUESTGEOLOCATIONDATA {
  DWORD                         cbSize;
  DWORD                         dwParams;
  DWORD                         dwExecutor;
  RILGEOLOCATIONTYPEMASK        dwLocationInformationMask;
  RILGEOLOCATIONREQUESTACCURACY dwLocationRequestAccuracy;
  RILGEOLOCATIONREQUESTINFO     rrRequestInformation;
} RILREQUESTGEOLOCATIONDATA, *LPRILREQUESTGEOLOCATIONDATA;