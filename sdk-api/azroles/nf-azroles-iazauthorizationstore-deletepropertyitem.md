# IAzAuthorizationStore::DeletePropertyItem

## Description

The **DeletePropertyItem** method removes the specified principal from the specified list of principals.

## Parameters

### `lPropId` [in]

Property ID of the list of principals from which to remove the principal specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_POLICY_ADMINS** | Can also be removed using the [DeletePolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletepolicyadministrator) method |
| **AZ_PROP_POLICY_ADMINS_NAME** | Can also be removed using the [DeletePolicyAdministratorName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletepolicyadministratorname) method |
| **AZ_PROP_POLICY_READERS** | Can also be removed using the [DeletePolicyReader](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletepolicyreader) method |
| **AZ_PROP_POLICY_READERS_NAME** | Can also be removed using the [DeletePolicyReaderName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletepolicyreadername) method |
| **AZ_PROP_DELEGATED_POLICY_USERS** | Can also be removed using the [DeleteDelegatedPolicyUser](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletedelegatedpolicyuser) method |
| **AZ_PROP_DELEGATED_POLICY_USERS_NAME** | Can also be removed using the [DeleteDelegatedPolicyUserName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-deletedelegatedpolicyusername) method |

### `varProp` [in]

The principal to remove from the list of principals specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_POLICY_ADMINS_NAME, AZ_PROP_POLICY_READERS_NAME, or AZ_PROP_DELEGATED_POLICY_USERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to remove from the list. The account name must be in user principal name (UPN) format (for example, "someone@example.com").

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method to persist any changes made by this method.