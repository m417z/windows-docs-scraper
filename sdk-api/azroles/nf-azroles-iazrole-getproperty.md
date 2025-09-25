# IAzRole::GetProperty

## Description

The **GetProperty** method returns the [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_applicationdata) property |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value will always be **FALSE** because this object cannot have child objects. |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_description) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_name) property |
| **AZ_PROP_ROLE_APP_MEMBERS** | Also accessed through the [AppMembers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_appmembers) property |
| **AZ_PROP_ROLE_MEMBERS** | Also accessed through the [Members](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_members) property |
| **AZ_PROP_ROLE_MEMBERS_NAME** | Also accessed through the [MembersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_membersname) property |
| **AZ_PROP_ROLE_OPERATIONS** | Also accessed through the [Operations](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_operations) property |
| **AZ_PROP_ROLE_TASKS** | Also accessed through the [Tasks](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_tasks) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object property.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.