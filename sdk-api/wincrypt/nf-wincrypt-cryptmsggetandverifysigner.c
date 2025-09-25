BOOL CryptMsgGetAndVerifySigner(
  [in]                HCRYPTMSG      hCryptMsg,
  [in]                DWORD          cSignerStore,
  [in, optional]      HCERTSTORE     *rghSignerStore,
  [in]                DWORD          dwFlags,
  [out, optional]     PCCERT_CONTEXT *ppSigner,
  [in, out, optional] DWORD          *pdwSignerIndex
);