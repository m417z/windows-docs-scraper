# IOCSPAdmin::GetSecurity

## Description

The **GetSecurity** method gets security descriptor information for an Online Certificate Status Protocol (OCSP) responder server.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `pVal` [out]

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The security descriptor information.

## Remarks

This method calls the [ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) function to create a string value in [Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)