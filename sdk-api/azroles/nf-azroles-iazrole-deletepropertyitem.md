# IAzRole::DeletePropertyItem

## Description

The **DeletePropertyItem** method removes the specified entity from the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list from which to remove the entity specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_ROLE_APP_MEMBERS** | Can also be removed using the [DeleteAppMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-deleteappmember) method |
| **AZ_PROP_ROLE_MEMBERS** | Can also be removed using the [DeleteMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-deletemember) method |
| **AZ_PROP_ROLE_MEMBERS_NAME** | Can also be removed using the [DeleteMemberName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-deletemembername) method |
| **AZ_PROP_ROLE_OPERATIONS** | Can also be removed using the [DeleteOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-deleteoperation) method |
| **AZ_PROP_ROLE_TASKS** | Can also be removed using the [DeleteTask](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-deletetask) method |

### `varProp` [in]

Entity to remove from the list specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_ROLE_MEMBERS is specified for the *lPropId* parameter, the string is the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the Windows account to remove from the list. If AZ_PROP_ROLE_MEMBERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to remove from the list. The account name can be in either user principal name (UPN) format (for example, "someone@example.com") or in the "ExampleDomain\UserName" format. If AZ_PROP_ROLE_APP_MEMBERS is specified for the *lPropId* parameter, the string is the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object to remove from the list.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.