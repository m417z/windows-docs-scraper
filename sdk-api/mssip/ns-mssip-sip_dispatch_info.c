typedef struct SIP_DISPATCH_INFO_ {
  DWORD                        cbSize;
  HANDLE                       hSIP;
  pCryptSIPGetSignedDataMsg    pfGet;
  pCryptSIPPutSignedDataMsg    pfPut;
  pCryptSIPCreateIndirectData  pfCreate;
  pCryptSIPVerifyIndirectData  pfVerify;
  pCryptSIPRemoveSignedDataMsg pfRemove;
} SIP_DISPATCH_INFO, *LPSIP_DISPATCH_INFO;