BOOL CryptDecodeMessage(
  [in]                DWORD                       dwMsgTypeFlags,
  [in]                PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
  [in]                PCRYPT_VERIFY_MESSAGE_PARA  pVerifyPara,
  [in]                DWORD                       dwSignerIndex,
  [in]                const BYTE                  *pbEncodedBlob,
  [in]                DWORD                       cbEncodedBlob,
  [in]                DWORD                       dwPrevInnerContentType,
  [out, optional]     DWORD                       *pdwMsgType,
  [out, optional]     DWORD                       *pdwInnerContentType,
  [out, optional]     BYTE                        *pbDecoded,
  [in, out, optional] DWORD                       *pcbDecoded,
  [out, optional]     PCCERT_CONTEXT              *ppXchgCert,
  [out, optional]     PCCERT_CONTEXT              *ppSignerCert
);