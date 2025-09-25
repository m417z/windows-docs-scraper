NTSTATUS FLTAPI FltSetSecurityObject(
  [in] PFLT_INSTANCE        Instance,
  [in] PFILE_OBJECT         FileObject,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);