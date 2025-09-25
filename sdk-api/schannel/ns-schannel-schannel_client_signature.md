# SCHANNEL_CLIENT_SIGNATURE structure

## Description

Specifies a client signature when a call to the [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function cannot access the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) for a client certificate (in this case, the function returns **SEC_I_SIGNATURE_NEEDED**).

## Members

### `cbLength`

The size, in bytes, of this structure.

### `aiHash`

The ID of the algorithm used to compute the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the certificate.

### `cbHash`

The size, in bytes, of the **HashValue** array.

### `HashValue`

An array of byte values that specify the hash of the certificate.

### `CertThumbprint`

An array of byte values that specify the certificate thumbprint.

## Remarks

Add a client signature to a client context by using this structure as the value of the *pInput* parameter in a call to the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function.