NTSTATUS LsaAddAccountRights(
  [in] LSA_HANDLE          PolicyHandle,
  [in] PSID                AccountSid,
  [in] PLSA_UNICODE_STRING UserRights,
  [in] ULONG               CountOfRights
);