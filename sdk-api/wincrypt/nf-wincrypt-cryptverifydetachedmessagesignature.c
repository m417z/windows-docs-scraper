BOOL CryptVerifyDetachedMessageSignature(
  [in]            PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
  [in]            DWORD                      dwSignerIndex,
  [in]            const BYTE                 *pbDetachedSignBlob,
  [in]            DWORD                      cbDetachedSignBlob,
  [in]            DWORD                      cToBeSigned,
  [in]            const BYTE * []            rgpbToBeSigned,
  [in]            DWORD []                   rgcbToBeSigned,
  [out, optional] PCCERT_CONTEXT             *ppSignerCert
);