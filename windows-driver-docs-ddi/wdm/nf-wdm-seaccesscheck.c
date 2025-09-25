BOOLEAN SeAccessCheck(
  [in]  PSECURITY_DESCRIPTOR      SecurityDescriptor,
  [in]  PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
  [in]  BOOLEAN                   SubjectContextLocked,
  [in]  ACCESS_MASK               DesiredAccess,
  [in]  ACCESS_MASK               PreviouslyGrantedAccess,
  [out] PPRIVILEGE_SET            *Privileges,
  [in]  PGENERIC_MAPPING          GenericMapping,
  [in]  KPROCESSOR_MODE           AccessMode,
  [out] PACCESS_MASK              GrantedAccess,
  [out] PNTSTATUS                 AccessStatus
);