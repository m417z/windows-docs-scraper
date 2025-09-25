# IAzApplicationGroup::GetProperty

## Description

The **GetProperty** method returns the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value will always be **FALSE** because this object cannot have child objects. |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_description) property |
| **AZ_PROP_GROUP_APP_MEMBERS** | Also accessed through the [AppMembers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_appmembers) property |
| **AZ_PROP_GROUP_APP_NON_MEMBERS** | Also accessed through the [AppNonMembers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_appnonmembers) property |
| **AZ_PROP_GROUP_MEMBERS** | Also accessed through the [Members](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_members) property |
| **AZ_PROP_GROUP_MEMBERS_NAME** | Also accessed through the [MembersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_membersname) property |
| **AZ_PROP_GROUP_NON_MEMBERS** | Also accessed through the [NonMembers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembers) property |
| **AZ_PROP_GROUP_NON_MEMBERS_NAME** | Also accessed through the [NonMembersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembersname) property |
| **AZ_PROP_GROUP_TYPE** | Also accessed through the [Type](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_type) property |
| **AZ_PROP_GROUP_LDAP_QUERY** | Also accessed through the [LdapQuery](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_ldapquery) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_name) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.