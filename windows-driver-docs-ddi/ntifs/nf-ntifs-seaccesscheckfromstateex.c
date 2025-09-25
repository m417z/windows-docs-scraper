BOOLEAN SeAccessCheckFromStateEx(
  PSECURITY_DESCRIPTOR SecurityDescriptor,
  PACCESS_TOKEN        PrimaryToken,
  PACCESS_TOKEN        ClientToken,
  ACCESS_MASK          DesiredAccess,
  ACCESS_MASK          PreviouslyGrantedAccess,
  PPRIVILEGE_SET       *Privileges,
  PGENERIC_MAPPING     GenericMapping,
  KPROCESSOR_MODE      AccessMode,
  PACCESS_MASK         GrantedAccess,
  PNTSTATUS            AccessStatus
);