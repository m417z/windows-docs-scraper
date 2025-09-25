typedef struct _SID_INFO {
  PSID  pSid;
  PWSTR pwzCommonName;
  PWSTR pwzClass;
  PWSTR pwzUPN;
} SID_INFO, *PSID_INFO;