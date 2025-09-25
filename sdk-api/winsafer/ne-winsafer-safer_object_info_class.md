# SAFER_OBJECT_INFO_CLASS enumeration

## Description

The **SAFER_OBJECT_INFO_CLASS** enumeration type defines the type of information requested about a Safer object.

## Constants

### `SaferObjectLevelId:1`

Queries for the LEVELID constant.

### `SaferObjectScopeId`

Queries for the user or machine scope.

### `SaferObjectFriendlyName`

Queries for the display name.

### `SaferObjectDescription`

Queries for the description.

### `SaferObjectBuiltin`

### `SaferObjectDisallowed`

### `SaferObjectDisableMaxPrivilege`

### `SaferObjectInvertDeletedPrivileges`

### `SaferObjectDeletedPrivileges`

### `SaferObjectDefaultOwner`

### `SaferObjectSidsToDisable`

### `SaferObjectRestrictedSidsInverted`

### `SaferObjectRestrictedSidsAdded`

### `SaferObjectAllIdentificationGuids`

Queries for all levels.

### `SaferObjectSingleIdentification`

Queries for a single additional rule.

### `SaferObjectExtendedError`

Queries for additional error codes set during rule processing.

## Remarks

The **SAFER_OBJECT_INFO_CLASS** enumeration type is used by the [SaferGetLevelInformation](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-safergetlevelinformation) function.