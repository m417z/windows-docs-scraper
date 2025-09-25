typedef struct FWPM_SESSION0_ {
  GUID               sessionKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  UINT32             txnWaitTimeoutInMSec;
  DWORD              processId;
  SID                *sid;
  wchar_t            *username;
  BOOL               kernelMode;
} FWPM_SESSION0;