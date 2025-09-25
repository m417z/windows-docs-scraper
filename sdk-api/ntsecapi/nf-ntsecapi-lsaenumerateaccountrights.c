NTSTATUS LsaEnumerateAccountRights(
  [in]  LSA_HANDLE          PolicyHandle,
  [in]  PSID                AccountSid,
  [out] PLSA_UNICODE_STRING *UserRights,
  [out] PULONG              CountOfRights
);