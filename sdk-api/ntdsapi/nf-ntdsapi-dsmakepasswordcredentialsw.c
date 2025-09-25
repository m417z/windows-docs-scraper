NTDSAPI DWORD DsMakePasswordCredentialsW(
  [in]  LPCWSTR                  User,
  [in]  LPCWSTR                  Domain,
  [in]  LPCWSTR                  Password,
  [out] RPC_AUTH_IDENTITY_HANDLE *pAuthIdentity
);