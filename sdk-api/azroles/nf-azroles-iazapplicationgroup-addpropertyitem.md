# IAzApplicationGroup::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified entity to the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list to which to add the entity specified by the _varProp_ parameter.

The following table shows the possible values:

| Value | Meaning |
|--------|--------|
| `AZ_PROP_GROUP_APP_MEMBERS` | Can also be added using the [AddAppMember](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addappmember) method. |
| `AZ_PROP_GROUP_APP_NON_MEMBERS` | Can also be added using the [AddAppNonMember](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addappnonmember) method. |
| `AZ_PROP_GROUP_MEMBERS` | Can also be added using the [AddMember](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addmember) method. |
| `AZ_PROP_GROUP_MEMBERS_NAME` | Can also be added using the [AddMemberName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addmembername) method. |
| `AZ_PROP_GROUP_NON_MEMBERS` | Can also be added using the [AddNonMember](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addnonmember) method. |
| `AZ_PROP_GROUP_NON_MEMBERS_NAME` | Can also be added using the [AddNonMemberName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addnonmembername) method. |

### `varProp`

TBD

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.

## See also

[AddMember](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-addmember)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit)