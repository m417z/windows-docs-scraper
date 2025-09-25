BOOL CertAddEncodedCTLToStore(
  [in]            HCERTSTORE    hCertStore,
  [in]            DWORD         dwMsgAndCertEncodingType,
  [in]            const BYTE    *pbCtlEncoded,
  [in]            DWORD         cbCtlEncoded,
  [in]            DWORD         dwAddDisposition,
  [out, optional] PCCTL_CONTEXT *ppCtlContext
);