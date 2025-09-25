# IXpsSigningOptions::GetSignatureId

## Description

Gets the value of the **Id** attribute of the **Signature** element.

## Parameters

### `signatureId` [out, retval]

The value of the **Id** attribute of the **Signature** element. If the **Id** attribute is not present, the method returns an empty string.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

This method allocates the memory used by the string that is returned in *signatureId*. If *signatureId* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

The default value of the signature ID is an empty string.

## See also

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)