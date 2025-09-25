# IAzApplicationGroup::SetProperty

## Description

The **SetProperty** method sets the specified value to the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property to set. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_description) property |
| **AZ_PROP_GROUP_TYPE** | Also accessed through the [Type](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_type) property |
| **AZ_PROP_GROUP_LDAP_QUERY** | Also accessed through the [LdapQuery](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_ldapquery) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_name) property |

### `varProp` [in]

Value to set to the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object property specified by the *lPropId* parameter. The following table shows the type of data that must be used depending on the value of the *lPropId* parameter.

| *lPropId* value | Data type (C++/Visual Basic) |
| --- | --- |
| **AZ_PROP_DESCRIPTION** | **BSTR**/**String** |
| **AZ_PROP_GROUP_LDAP_QUERY** | **BSTR**/**String** |
| **AZ_PROP_GROUP_TYPE** | **LONG**/**Long** |
| **AZ_PROP_NAME** | **BSTR**/**String** |

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.