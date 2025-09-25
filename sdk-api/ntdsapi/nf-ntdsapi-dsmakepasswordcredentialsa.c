NTDSAPI DWORD DsMakePasswordCredentialsA(
  [in]  LPCSTR                   User,
  [in]  LPCSTR                   Domain,
  [in]  LPCSTR                   Password,
  [out] RPC_AUTH_IDENTITY_HANDLE *pAuthIdentity
);