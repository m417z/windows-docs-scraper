# DSROLE_UPGRADE_STATUS_INFO structure

## Description

The **DSROLE_UPGRADE_STATUS_INFO** structure is used with the [DsRoleGetPrimaryDomainInformation](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolegetprimarydomaininformation) function to contain domain upgrade status data.

## Members

### `OperationState`

Specifies the current state of the upgrade. This member can be one of the following values.

#### 0

An upgrade is not in progress.

#### DSROLE_UPGRADE_IN_PROGRESS

An upgrade is in progress.

### `PreviousServerState`

If an upgrade is in progress, this member contains one of the [DSROLE_SERVER_STATE](https://learn.microsoft.com/windows/desktop/api/dsrole/ne-dsrole-dsrole_server_state) values that indicate the previous role of the server.

## See also

[Directory Service Structures](https://learn.microsoft.com/windows/desktop/AD/directory-service-structures)

[DsRoleGetPrimaryDomainInformation](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolegetprimarydomaininformation)