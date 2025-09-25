BOOL CryptMsgEncodeAndSignCTL(
  [in]      DWORD                    dwMsgEncodingType,
  [in]      PCTL_INFO                pCtlInfo,
  [in]      PCMSG_SIGNED_ENCODE_INFO pSignInfo,
  [in]      DWORD                    dwFlags,
  [out]     BYTE                     *pbEncoded,
  [in, out] DWORD                    *pcbEncoded
);