BOOL CryptMsgVerifyCountersignatureEncodedEx(
  [in, optional] HCRYPTPROV_LEGACY hCryptProv,
  [in]           DWORD             dwEncodingType,
  [in]           PBYTE             pbSignerInfo,
  [in]           DWORD             cbSignerInfo,
  [in]           PBYTE             pbSignerInfoCountersignature,
  [in]           DWORD             cbSignerInfoCountersignature,
  [in]           DWORD             dwSignerType,
  [in]           void              *pvSigner,
                 DWORD             dwFlags,
                 void              *pvExtra
);