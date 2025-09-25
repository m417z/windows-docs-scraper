typedef struct _DDCAPBUFFINFO {
  DWORD         dwFieldNumber;
  DWORD         bPolarity;
  LARGE_INTEGER liTimeStamp;
  DWORD         ddRVal;
} DDCAPBUFFINFO, *LPDDCAPBUFFINFO;