# OP_CERT_PFX_STORE structure

Contains a serialized PFX structure.

## Members

### pTemplateName

Must be set to the name of the certificate template used to create the certificate.

### ulPrivateKeyExportPolicy

Contains one value from the [**X509PrivateKeyExportFlags**](https://learn.microsoft.com/windows/win32/api/certenroll/ne-certenroll-x509privatekeyexportflags) enumeration.

### pPolicyServerUrl

Must be set the URL of the policy server.

### ulPolicyServerUrlFlags

Contains one value from the [**PolicyServerUrlFlags**](https://learn.microsoft.com/windows/win32/api/certenroll/ne-certenroll-policyserverurlflags) enumeration.

### pPolicyServerId

Contains a string that uniquely identifies the policy server

### cbPfx

Contains the size of pPfx in bytes.

### pPfx

Contains a serialized PFX structure (see [**RFC 7292**](https://tools.ietf.org/html/rfc7292)).

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)