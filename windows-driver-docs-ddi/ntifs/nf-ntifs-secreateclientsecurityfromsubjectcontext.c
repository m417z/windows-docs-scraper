NTSTATUS SeCreateClientSecurityFromSubjectContext(
  [in]  PSECURITY_SUBJECT_CONTEXT    SubjectContext,
  [in]  PSECURITY_QUALITY_OF_SERVICE ClientSecurityQos,
  [in]  BOOLEAN                      ServerIsRemote,
  [out] PSECURITY_CLIENT_CONTEXT     ClientContext
);