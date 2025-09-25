VOID SeTokenGetNoChildProcessRestricted(
  [in]  PACCESS_TOKEN Token,
  [out] PBOOLEAN      Enforced,
  [out] PBOOLEAN      UnlessSecure,
  [out] PBOOLEAN      AuditOnly
);