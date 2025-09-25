# IAzAuthorizationStore::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified principal to the specified list of principals.

## Parameters

### `lPropId` [in]

Property ID of the list of principals to which to add the principal specified by the *varProp* parameter. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_POLICY_ADMINS** | Can also be added by using the [AddPolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-addpolicyadministrator) method. |
| **AZ_PROP_POLICY_ADMINS_NAME** | Can also be added by using the [AddPolicyAdministratorName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-addpolicyadministratorname) method. |
| **AZ_PROP_POLICY_READERS** | Can also be added by using the [AddPolicyReader](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-addpolicyreader) method. |
| **AZ_PROP_POLICY_READERS_NAME** | Can also be added by using the [AddPolicyReaderName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-addpolicyreadername) method. |
| **AZ_PROP_DELEGATED_POLICY_USERS** | Can also be added by using the [AddDelegatedPolicyUser](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-adddelegatedpolicyuser) method. |
| **AZ_PROP_DELEGATED_POLICY_USERS_NAME** | Can also be added by using the [AddDelegatedPolicyUserName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-adddelegatedpolicyusername) method. |

### `varProp` [in]

Principal to add to the list of principals specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_POLICY_ADMINS_NAME, AZ_PROP_POLICY_READERS_NAME, or AZ_PROP_DELEGATED_POLICY_USERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to add to the list. The account name must be in [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) format (for example, "someone@example.com").

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method to persist any changes made by this method.