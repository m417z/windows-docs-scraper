# AUTHZ_SID_OPERATION enumeration

## Description

The **AUTHZ_SID_OPERATION** enumeration indicates the type of SID operations that can be made by a call to the [AuthzModifySids](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifysids) function.

## Constants

### `AUTHZ_SID_OPERATION_NONE:0`

Do not modify anything.

### `AUTHZ_SID_OPERATION_REPLACE_ALL`

Deletes all existing SIDs and replaces them with the specified SIDs. If the replacement SIDs are not specified, all existing SIDs are deleted. This operation can be specified only once and must be the only operation specified.

### `AUTHZ_SID_OPERATION_ADD`

Adds a new SID. If the SID already exists, the call fails.

### `AUTHZ_SID_OPERATION_DELETE`

Deletes the specified SID. If no matching SID is found, no modifications are done and the call fails.

### `AUTHZ_SID_OPERATION_REPLACE`

Replaces the existing SID with the specified SID. If the SID does not already exist, then adds the SID.