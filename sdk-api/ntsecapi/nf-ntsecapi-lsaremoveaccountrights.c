NTSTATUS LsaRemoveAccountRights(
  [in] LSA_HANDLE          PolicyHandle,
  [in] PSID                AccountSid,
  [in] BOOLEAN             AllRights,
  [in] PLSA_UNICODE_STRING UserRights,
  [in] ULONG               CountOfRights
);