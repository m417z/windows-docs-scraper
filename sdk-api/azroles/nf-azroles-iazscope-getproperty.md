# IAzScope::GetProperty

## Description

The **GetProperty** method returns the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_applicationdata) property |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value is **TRUE** if the current user has permission; otherwise, **FALSE**. |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_description) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_name) property |
| **AZ_PROP_POLICY_ADMINS** | Also accessed through the [PolicyAdministrators](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_policyadministrators) property |
| **AZ_PROP_POLICY_ADMINS_NAME** | Also accessed through the [PolicyAdministratorsName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_policyadministratorsname) property |
| **AZ_PROP_POLICY_READERS** | Also accessed through the [PolicyReaders](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_policyreaders) property |
| **AZ_PROP_POLICY_READERS_NAME** | Also accessed through the [PolicyReadersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_policyreadersname) property |
| **AZ_PROP_SCOPE_BIZRULES_WRITABLE** | Also accessed through the [BizrulesWritable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_bizruleswritable) property |
| **AZ_PROP_SCOPE_CAN_BE_DELEGATED** | Also accessed through the [CanBeDelegated](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_canbedelegated) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object property.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.