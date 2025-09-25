# DsRoleGetPrimaryDomainInformation function

## Description

The **DsRoleGetPrimaryDomainInformation** function retrieves state data for the computer. This data includes the state of the directory service installation and domain data.

## Parameters

### `lpServer` [in]

Pointer to null-terminated Unicode string that contains the name of the computer on which to call the function. If this parameter is **NULL**, the local computer is used.

### `InfoLevel` [in]

Contains one of the [DSROLE_PRIMARY_DOMAIN_INFO_LEVEL](https://learn.microsoft.com/windows/desktop/api/dsrole/ne-dsrole-dsrole_primary_domain_info_level) values that specify the type of data to retrieve. This parameter also determines the format of the data supplied in *Buffer*.

### `Buffer` [out]

Pointer to the address of a buffer that receives the requested data. The format of this data depends on the value of the *InfoLevel* parameter.

The caller must free this memory when it is no longer required by calling [DsRoleFreeMemory](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolefreememory).

## Return value

If the function is successful, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following values.

## See also

[DSROLE_OPERATION_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_operation_state_info)

[DSROLE_PRIMARY_DOMAIN_INFO_BASIC](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_primary_domain_info_basic)

[DSROLE_UPGRADE_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_upgrade_status_info)

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsRoleFreeMemory](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolefreememory)