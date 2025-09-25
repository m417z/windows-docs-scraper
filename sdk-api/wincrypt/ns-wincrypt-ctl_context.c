typedef struct _CTL_CONTEXT {
  DWORD      dwMsgAndCertEncodingType;
  BYTE       *pbCtlEncoded;
  DWORD      cbCtlEncoded;
  PCTL_INFO  pCtlInfo;
  HCERTSTORE hCertStore;
  HCRYPTMSG  hCryptMsg;
  BYTE       *pbCtlContent;
  DWORD      cbCtlContent;
} CTL_CONTEXT, *PCTL_CONTEXT;