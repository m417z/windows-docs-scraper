BOOLEAN SePrivilegeCheck(
  [in, out] PPRIVILEGE_SET            RequiredPrivileges,
  [in]      PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
  [in]      KPROCESSOR_MODE           AccessMode
);