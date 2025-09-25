BOOL CryptVerifyMessageSignature(
  [in]            PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
  [in]            DWORD                      dwSignerIndex,
  [in]            const BYTE                 *pbSignedBlob,
  [in]            DWORD                      cbSignedBlob,
  [out]           BYTE                       *pbDecoded,
  [in, out]       DWORD                      *pcbDecoded,
  [out, optional] PCCERT_CONTEXT             *ppSignerCert
);