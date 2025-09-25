# IAzScope::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified principal to the specified list of principals.

## Parameters

### `lPropId` [in]

Property ID of the list of principals to which to add the principal specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_POLICY_ADMINS** | Can also be added using the [AddPolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-addpolicyadministrator) method |
| **AZ_PROP_POLICY_ADMINS_NAME** | Can also be added using the [AddPolicyAdministratorName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-addpolicyadministratorname) method |
| **AZ_PROP_POLICY_READERS** | Can also be added using the [AddPolicyReader](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-addpolicyreader) method |
| **AZ_PROP_POLICY_READERS_NAME** | Can also be added using the [AddPolicyReaderName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-addpolicyreadername) method |

### `varProp` [in]

Principal to add to the list of principals specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

If AZ_PROP_POLICY_ADMINS or AZ_PROP_POLICY_READERS is specified for the *lPropId* parameter, the string is the text form of the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the Windows account to add to the list. If AZ_PROP_POLICY_ADMINS_NAME or AZ_PROP_POLICY_READERS_NAME is specified for the *lPropId* parameter, the string is the account name of the account to add to the list. The account name can be in either user principal name (UPN) format (for example, "someone@example.com") or in the "ExampleDomain\UserName" format.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-submit) method to persist any changes made by this method.