# IXpsSigningOptions::GetSignatureMethod

## Description

Gets the signature method.

## Parameters

### `signatureMethod` [out, retval]

The signature method that is expressed as a URI. If no signature method has been set, a **NULL** pointer is returned.

The following signature methods have been tested in Windows 7:

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

A signature method must be set before signing.

When a new instance of this interface is returned by [IXpsSignatureManager::CreateSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-createsigningoptions), the SignatureMethod and DigestMethod properties are not valid; they must be initialized before the new interface can be used as a parameter of the [Sign](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-sign) method.

This method allocates the memory used by the string that is returned in *signatureMethod*. If *signatureMethod* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[Cryptography Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)