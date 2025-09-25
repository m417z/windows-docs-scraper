typedef enum _SAFER_OBJECT_INFO_CLASS {
  SaferObjectLevelId = 1,
  SaferObjectScopeId,
  SaferObjectFriendlyName,
  SaferObjectDescription,
  SaferObjectBuiltin,
  SaferObjectDisallowed,
  SaferObjectDisableMaxPrivilege,
  SaferObjectInvertDeletedPrivileges,
  SaferObjectDeletedPrivileges,
  SaferObjectDefaultOwner,
  SaferObjectSidsToDisable,
  SaferObjectRestrictedSidsInverted,
  SaferObjectRestrictedSidsAdded,
  SaferObjectAllIdentificationGuids,
  SaferObjectSingleIdentification,
  SaferObjectExtendedError
} SAFER_OBJECT_INFO_CLASS;