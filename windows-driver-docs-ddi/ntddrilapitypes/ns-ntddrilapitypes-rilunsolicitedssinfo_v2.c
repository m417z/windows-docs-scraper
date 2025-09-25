typedef struct RILUNSOLICITEDSSINFO_V2 {
  DWORD                                cbSize;
  DWORD                                dwParams;
  DWORD                                dwExecutor;
  DWORD                                dwID;
  RILUNSOLICITEDSSINFONOTIFICATIONCODE dwNotificationCode;
  RILADDRESS                           raAddress;
  RILSUBADDRESS                        rsaSubAddress;
  DWORD                                dwCUGIndex;
  DWORD                                dwHistorynfoLength;
  WCHAR                                wszHistoryInfo[1];
} RILUNSOLICITEDSSINFO_V2, *LPRILUNSOLICITEDSSINFO_V2, RILUNSOLICITEDSSINFO, *LPRILUNSOLICITEDSSINFO;