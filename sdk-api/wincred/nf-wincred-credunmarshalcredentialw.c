BOOL CredUnmarshalCredentialW(
  [in]  LPCWSTR            MarshaledCredential,
  [out] PCRED_MARSHAL_TYPE CredType,
  [out] PVOID              *Credential
);