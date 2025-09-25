# IAzRole::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified entity to the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list to which to add the entity specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_ROLE_APP_MEMBERS** | Can also be added using the [AddAppMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-addappmember) method |
| **AZ_PROP_ROLE_MEMBERS** | Can also be added using the [AddMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-addmember) method |
| **AZ_PROP_ROLE_MEMBERS_NAME** | Can also be added using the [AddMemberName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-addmembername) method |
| **AZ_PROP_ROLE_OPERATIONS** | Can also be added using the [AddOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-addoperation) method |
| **AZ_PROP_ROLE_TASKS** | Can also be added using the [AddTask](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-addtask) method |

### `varProp` [in]

Entity to add to the list specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_ROLE_MEMBERS is specified for the *lPropId* parameter, the string is the text form of the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the Windows account to add to the list. If AZ_PROP_ROLE_MEMBERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to add to the list. The account name can be in either user principal name (UPN) format (for example, "someone@example.com") or in the "ExampleDomain\UserName" format. If AZ_PROP_ROLE_APP_MEMBERS is specified for the *lPropId* parameter, the string is the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object to add to the list.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.