BOOL CryptMsgVerifyCountersignatureEncoded(
  [in] HCRYPTPROV_LEGACY hCryptProv,
  [in] DWORD             dwEncodingType,
  [in] PBYTE             pbSignerInfo,
  [in] DWORD             cbSignerInfo,
  [in] PBYTE             pbSignerInfoCountersignature,
  [in] DWORD             cbSignerInfoCountersignature,
  [in] PCERT_INFO        pciCountersigner
);