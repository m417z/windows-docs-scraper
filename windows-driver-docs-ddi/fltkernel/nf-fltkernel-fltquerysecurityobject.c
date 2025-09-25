NTSTATUS FLTAPI FltQuerySecurityObject(
  [in]            PFLT_INSTANCE        Instance,
  [in]            PFILE_OBJECT         FileObject,
  [in]            SECURITY_INFORMATION SecurityInformation,
  [in, out]       PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]            ULONG                Length,
  [out, optional] PULONG               LengthNeeded
);