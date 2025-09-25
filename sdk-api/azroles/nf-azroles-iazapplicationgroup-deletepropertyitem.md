# IAzApplicationGroup::DeletePropertyItem

## Description

The **DeletePropertyItem** method removes the specified entity from the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list from which to remove the entity specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_GROUP_APP_MEMBERS** | Can also be removed using the [DeleteAppMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deleteappmember) method |
| **AZ_PROP_GROUP_APP_NON_MEMBERS** | Can also be removed using the [DeleteAppNonMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deleteappnonmember) method |
| **AZ_PROP_GROUP_MEMBERS** | Can also be removed using the [DeleteMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deletemember) method |
| **AZ_PROP_GROUP_MEMBERS_NAME** | Can also be removed using the [DeleteMemberName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deletemembername) method |
| **AZ_PROP_GROUP_NON_MEMBERS** | Can also be removed using the [DeleteNonMember](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deletenonmember) method |
| **AZ_PROP_GROUP_NON_MEMBERS_NAME** | Can also be removed using the [DeleteNonMemberName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-deletenonmembername) method |

### `varProp` [in]

The entity to remove from the list specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_GROUP_MEMBERS_NAME or AZ_PROP_GROUP_NON_MEMBERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to remove from the list. The account name must be in user principal name (UPN) format (for example, "someone@example.com"). If AZ_PROP_GROUP_APP_MEMBERS or AZ_PROP_GROUP_APP_NON_MEMBERS is specified for the *lPropId* parameter, the string is the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object to remove from the list.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.