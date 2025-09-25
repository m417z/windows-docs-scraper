NTSTATUS LsaRetrievePrivateData(
  [in]  LSA_HANDLE          PolicyHandle,
  [in]  PLSA_UNICODE_STRING KeyName,
  [out] PLSA_UNICODE_STRING *PrivateData
);