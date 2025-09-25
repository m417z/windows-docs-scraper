LSA_GET_USER_AUTH_DATA LsaGetUserAuthData;

NTSTATUS LsaGetUserAuthData(
  [in]  PVOID UserHandle,
  [out] PUCHAR *UserAuthData,
  [out] PULONG UserAuthDataSize
)
{...}