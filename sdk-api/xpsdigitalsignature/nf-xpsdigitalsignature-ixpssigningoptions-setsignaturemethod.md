# IXpsSigningOptions::SetSignatureMethod

## Description

Sets the signature method.

## Parameters

### `signatureMethod` [in]

The signature method expressed as a URI.

This parameter must refer to a valid signature method. The following signature methods have been tested in Windows 7:

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The signature method must be set before signing.

When a new instance of this interface is returned by [IXpsSignatureManager::CreateSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-createsigningoptions), the SignatureMethod and DigestMethod properties are not initialized; they must be initialized before the new interface can be used as a parameter of the [Sign](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-sign) method.

The URI in *signatureMethod* must be the URI of a valid signing algorithm, such as http://www.w3.org/2000/09/xmldsig#rsa-sha1, and it must be
supported by the signing certificate.

## See also

[Cryptography Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)