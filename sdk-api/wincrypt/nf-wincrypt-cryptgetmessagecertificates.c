HCERTSTORE CryptGetMessageCertificates(
  [in] DWORD             dwMsgAndCertEncodingType,
  [in] HCRYPTPROV_LEGACY hCryptProv,
  [in] DWORD             dwFlags,
  [in] const BYTE        *pbSignedBlob,
  [in] DWORD             cbSignedBlob
);