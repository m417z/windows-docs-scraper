LSA_EXPAND_AUTH_DATA_FOR_DOMAIN LsaExpandAuthDataForDomain;

NTSTATUS LsaExpandAuthDataForDomain(
  [in]  PUCHAR UserAuthData,
  [in]  ULONG UserAuthDataSize,
  [in]  PVOID Reserved,
  [out] PUCHAR *ExpandedAuthData,
  [out] PULONG ExpandedAuthDataSize
)
{...}