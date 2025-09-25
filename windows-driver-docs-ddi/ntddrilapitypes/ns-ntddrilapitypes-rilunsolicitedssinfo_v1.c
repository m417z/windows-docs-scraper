typedef struct RILUNSOLICITEDSSINFO_V1 {
  DWORD                                cbSize;
  DWORD                                dwParams;
  DWORD                                dwExecutor;
  DWORD                                dwID;
  RILUNSOLICITEDSSINFONOTIFICATIONCODE dwNotificationCode;
  RILADDRESS                           raAddress;
  RILSUBADDRESS                        rsaSubAddress;
  DWORD                                dwCUGIndex;
} RILUNSOLICITEDSSINFO_V1, *LPRILUNSOLICITEDSSINFO_V1;