# DsListRolesW function

## Description

The **DsListRoles** function lists roles recognized by the server.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `ppRoles` [out]

Pointer to a variable that receives a pointer to a
[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure containing the roles the server recognizes. The returned structure must be deallocated using
[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta).

The indexes of the array in the [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure indicate what data are contained by each array element. The following constants may be used to specify the desired index for a particular piece of data.

#### DS_ROLE_DOMAIN_OWNER

Server owns the domain.

#### DS_ROLE_INFRASTRUCTURE_OWNER

Server owns the infrastructure.

#### DS_ROLE_PDC_OWNER

Server owns the PDC.

#### DS_ROLE_RID_OWNER

Server owns the RID.

#### DS_ROLE_SCHEMA_OWNER

Server owns the schema.

##### - ppRoles.DS_ROLE_DOMAIN_OWNER

Server owns the domain.

##### - ppRoles.DS_ROLE_INFRASTRUCTURE_OWNER

Server owns the infrastructure.

##### - ppRoles.DS_ROLE_PDC_OWNER

Server owns the PDC.

##### - ppRoles.DS_ROLE_RID_OWNER

Server owns the RID.

##### - ppRoles.DS_ROLE_SCHEMA_OWNER

Server owns the schema.

## Return value

If the function returns a list of roles, the return value is **NO_ERROR**.

If the function fails, the return value can be one of the following error codes.

Individual name conversion errors are reported in the returned [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure.

## See also

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsListRoles as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).