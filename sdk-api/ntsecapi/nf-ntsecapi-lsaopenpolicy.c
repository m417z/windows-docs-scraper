NTSTATUS LsaOpenPolicy(
  [in]      PLSA_UNICODE_STRING    SystemName,
  [in]      PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
  [in]      ACCESS_MASK            DesiredAccess,
  [in, out] PLSA_HANDLE            PolicyHandle
);