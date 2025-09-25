# IAzScope::DeletePropertyItem

## Description

The **DeletePropertyItem** method removes the specified principal from the specified list of principals.

## Parameters

### `lPropId` [in]

Property ID of the list of principals from which to remove the principal specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_POLICY_ADMINS** | Can also be removed using the [DeletePolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-deletepolicyadministrator) method |
| **AZ_PROP_POLICY_ADMINS_NAME** | Can also be removed using the [DeletePolicyAdministratorName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-deletepolicyadministratorname) method |
| **AZ_PROP_POLICY_READERS** | Can also be removed using the [DeletePolicyReader](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-deletepolicyreader) method |
| **AZ_PROP_POLICY_READERS_NAME** | Can also be removed using the [DeletePolicyReaderName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-deletepolicyreadername) method |

### `varProp` [in]

Principal to remove from the list of principals specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_POLICY_ADMINS or AZ_PROP_POLICY_READERS is specified for the *lPropId* parameter, the string is the text form of the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the Windows account to remove from the list. If AZ_PROP_POLICY_ADMINS_NAME or AZ_PROP_POLICY_READERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to remove from the list. The account name can be in either user principal name (UPN) format (for example, "someone@example.com") or in the "ExampleDomain\UserName" format.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.