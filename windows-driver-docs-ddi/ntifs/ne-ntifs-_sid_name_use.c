typedef enum _SID_NAME_USE {
  SidTypeUser,
  SidTypeGroup,
  SidTypeDomain,
  SidTypeAlias,
  SidTypeWellKnownGroup,
  SidTypeDeletedAccount,
  SidTypeInvalid,
  SidTypeUnknown,
  SidTypeComputer,
  SidTypeLabel,
  SidTypeLogonSession
} SID_NAME_USE, *PSID_NAME_USE;