# IOCSPAdmin::SetSecurity

## Description

The **SetSecurity** method updates security descriptor information for an Online Certificate Status Protocol (OCSP) responder server.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `bstrVal` [in]

A string that contains the security descriptor information to assign to the responder server.

## Remarks

This method calls the [ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora) function to create a security descriptor from a string in [Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)