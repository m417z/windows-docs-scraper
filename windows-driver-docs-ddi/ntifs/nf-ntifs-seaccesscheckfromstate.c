BOOLEAN SeAccessCheckFromState(
  PSECURITY_DESCRIPTOR      SecurityDescriptor,
  PTOKEN_ACCESS_INFORMATION PrimaryTokenInformation,
  PTOKEN_ACCESS_INFORMATION ClientTokenInformation,
  ACCESS_MASK               DesiredAccess,
  ACCESS_MASK               PreviouslyGrantedAccess,
  PPRIVILEGE_SET            *Privileges,
  PGENERIC_MAPPING          GenericMapping,
  KPROCESSOR_MODE           AccessMode,
  PACCESS_MASK              GrantedAccess,
  PNTSTATUS                 AccessStatus
);