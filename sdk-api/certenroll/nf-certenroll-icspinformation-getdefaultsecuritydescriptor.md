# ICspInformation::GetDefaultSecurityDescriptor

## Description

The **GetDefaultSecurityDescriptor** method retrieves the default private key security descriptor.

## Parameters

### `MachineContext` [in]

A **VARIANT_BOOL** variable that indicates whether to retrieve the security descriptor for the computer or the user. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

### `pValue` [out]

Pointer to a **BSTR** variable that contains the security descriptor.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The property value could not be found. |
| ****NTE_BAD_TYPE**** | The cryptographic provider does not support security descriptors. |
| ****NTE_NOT_FOUND**** | The cryptographic provider does not support security descriptors. |
| ****NTE_BAD_KEY_STATE**** | The cryptographic provider does not support security descriptors. |

## Remarks

To use the security descriptor, you must call the [ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora) function included with the Microsoft Authorization API and specify the string returned by the **GetDefaultSecurityDescriptor** method. The function returns a pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

The default security descriptor is used to define access to private keys for the computer and user in the following manner:

* By default, only local administrators and services running under the LocalSystem account can access private keys associated with the computer account.
* When a provider stores the private key of a user in an encrypted file in the user profile, it uses a security descriptor to set access permissions to the file.

This method retrieves the default security descriptor that will be associated with the specified *MachineContext* parameter and the current provider if a new private key is created. You can use the default descriptor to create a custom descriptor. Custom descriptors are typically created when a private key associated with a computer context certificate must be used by a service running under an account other than the LocalSystem account.

Some cryptographic providers do not support security descriptors. Examples include smart card and hardware security module (HSM) providers.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)