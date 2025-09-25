ULONG EVNTAPI EventAccessControl(
  [in] LPGUID  Guid,
  [in] ULONG   Operation,
  [in] PSID    Sid,
  [in] ULONG   Rights,
  [in] BOOLEAN AllowOrDeny
);