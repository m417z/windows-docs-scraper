NTSYSAPI NTSTATUS ZwOpenSection(
  [out] PHANDLE            SectionHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);