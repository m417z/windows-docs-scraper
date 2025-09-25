# IXpsSigningOptions::SetDigestMethod

## Description

Sets the URI of the digest method.

## Parameters

### `digestMethod` [in]

The URI of the digest method.

This parameter must refer to the URI of a valid digest method. The following digest methods have been tested in Windows 7:

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The digest method must be set before signing.

When a new instance of this interface is returned by [IXpsSignatureManager::CreateSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-createsigningoptions), the SignatureMethod and DigestMethod properties are not initialized. They must be initialized before the new interface can be used as a parameter of the [Sign](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-sign) method.

Sets the string that identifies the URI of the algorithm that is used to digest the parts, relationships, and signature references. The following is an example of a valid URI: [http://www.w3.org/2000/09/xmldsig#sha1](http://www.w3.org/2000/09/xmldsig).

The signing certificate, signature method,
and digest method must be compatible with one another.

## See also

[Cryptography Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)