typedef struct _DD_GETFORMATDATA {
  DD_GETDRIVERINFO2DATA gdi2;
  DWORD                 dwFormatIndex;
  DDPIXELFORMAT         format;
} DD_GETFORMATDATA;