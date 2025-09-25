NTSTATUS FLTAPI FltBuildDefaultSecurityDescriptor(
  [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
  [in]  ACCESS_MASK          DesiredAccess
);