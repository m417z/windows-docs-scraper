# IX509PrivateKey::get_SecurityDescriptor

## Description

The **SecurityDescriptor** property specifies or retrieves the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

This property is read/write.

## Parameters

## Remarks

To use the security descriptor, you must call the [ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora) function included with the Microsoft Authorization API and specify the string returned by the [GetDefaultSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-getdefaultsecuritydescriptor) method.

The security descriptor is used to define access to private keys for the computer and user in the following manner:

* By default, only local administrators and services running under the LocalSystem account can access private keys associated with the computer account.
* When a CSP stores the private key of a user in an encrypted file in the user profile, it uses a security descriptor to set access permissions to the file.

If the key is not open when you specify a descriptor, the property value will be set when the key is opened.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)