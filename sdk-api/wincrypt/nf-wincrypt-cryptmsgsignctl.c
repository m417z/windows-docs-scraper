BOOL CryptMsgSignCTL(
  [in]      DWORD                    dwMsgEncodingType,
  [in]      BYTE                     *pbCtlContent,
  [in]      DWORD                    cbCtlContent,
  [in]      PCMSG_SIGNED_ENCODE_INFO pSignInfo,
  [in]      DWORD                    dwFlags,
  [out]     BYTE                     *pbEncoded,
  [in, out] DWORD                    *pcbEncoded
);