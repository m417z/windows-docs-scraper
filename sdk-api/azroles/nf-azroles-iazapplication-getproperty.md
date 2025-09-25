# IAzApplication::GetProperty

## Description

The **GetProperty** method returns the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_AUTHZ_INTERFACE_CLSID** | Also accessed through the [AuthzInterfaceClsid](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_authzinterfaceclsid) property |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_applicationdata) property |
| **AZ_PROP_APPLICATION_VERSION** | Also accessed through the [Version](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_version) property |
| **AZ_PROP_APPLY_STORE_SACL** | Also accessed through the [ApplyStoreSacl](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_applystoresacl) property |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value is **TRUE** if the current user has permission; otherwise, **FALSE**. |
| **AZ_PROP_DELEGATED_POLICY_USERS** | Also accessed through the [DelegatedPolicyUsers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_delegatedpolicyusers) property |
| **AZ_PROP_DELEGATED_POLICY_USERS_NAME** | Also accessed through the [DelegatedPolicyUsersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_delegatedpolicyusersname) property |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_description) property |
| **AZ_PROP_GENERATE_AUDITS** | Also accessed through the [GenerateAudits](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_generateaudits) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_name) property |
| **AZ_PROP_POLICY_ADMINS** | Also accessed through the [PolicyAdministrators](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyadministrators) property |
| **AZ_PROP_POLICY_ADMINS_NAME** | Also accessed through the [PolicyAdministratorsName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyadministratorsname) property |
| **AZ_PROP_POLICY_READERS** | Also accessed through the [PolicyReaders](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyreaders) property |
| **AZ_PROP_POLICY_READERS_NAME** | Also accessed through the [PolicyReadersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyreadersname) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.