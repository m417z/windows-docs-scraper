SECURITY_STATUS NCryptSecretAgreement(
  [in]  NCRYPT_KEY_HANDLE    hPrivKey,
  [in]  NCRYPT_KEY_HANDLE    hPubKey,
  [out] NCRYPT_SECRET_HANDLE *phAgreedSecret,
  [in]  DWORD                dwFlags
);