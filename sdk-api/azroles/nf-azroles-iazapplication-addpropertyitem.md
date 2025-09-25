# IAzApplication::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified principal to the specified list of principals.

## Parameters

### `lPropId` [in]

Property ID of the list of principals to which to add the principal specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_POLICY_ADMINS** | Can also be added using the [AddPolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-addpolicyadministrator) method |
| **AZ_PROP_POLICY_ADMINS_NAME** | Can also be added using the [AddPolicyAdministratorName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-addpolicyadministratorname) method |
| **AZ_PROP_POLICY_READERS** | Can also be added using the [AddPolicyReader](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-addpolicyreader) method |
| **AZ_PROP_POLICY_READERS_NAME** | Can also be added using the [AddPolicyReaderName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-addpolicyreadername) method |
| **AZ_PROP_DELEGATED_POLICY_USERS** | Can also be added using the [AddDelegatedPolicyUser](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-adddelegatedpolicyuser) method |
| **AZ_PROP_DELEGATED_POLICY_USERS_NAME** | Can also be added using the [AddDelegatedPolicyUserName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-adddelegatedpolicyusername) method |

### `varProp` [in]

Principal to add to the list of principals specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_POLICY_ADMINS_NAME, AZ_PROP_POLICY_READERS_NAME, or AZ_PROP_DELEGATED_POLICY_USERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to add to the list. The account name must be in user principal name (UPN) format (for example, "someone@example.com").

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.