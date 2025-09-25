BOOL CryptMsgCountersignEncoded(
  [in]      DWORD                    dwEncodingType,
  [in]      PBYTE                    pbSignerInfo,
  [in]      DWORD                    cbSignerInfo,
  [in]      DWORD                    cCountersigners,
  [in]      PCMSG_SIGNER_ENCODE_INFO rgCountersigners,
  [out]     PBYTE                    pbCountersignature,
  [in, out] PDWORD                   pcbCountersignature
);