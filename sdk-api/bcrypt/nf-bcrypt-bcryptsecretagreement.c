NTSTATUS BCryptSecretAgreement(
  [in]  BCRYPT_KEY_HANDLE    hPrivKey,
  [in]  BCRYPT_KEY_HANDLE    hPubKey,
  [out] BCRYPT_SECRET_HANDLE *phAgreedSecret,
  [in]  ULONG                dwFlags
);