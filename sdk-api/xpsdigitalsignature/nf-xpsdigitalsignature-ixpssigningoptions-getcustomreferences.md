# IXpsSigningOptions::GetCustomReferences

## Description

Gets a pointer to an [IOpcSignatureReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereferenceset) interface, which contains a set of signature custom references.

## Parameters

### `customReferenceSet` [out, retval]

A pointer to an [IOpcSignatureReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereferenceset) interface, which contains a set of signature custom references.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The custom reference set that this method returns is empty. To add a custom reference to this set, call the [Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturereferenceset-create) method of the interface that is returned in *customReferenceSet*.

If a custom object must be signed, a reference to that object must be added to the custom object set. For information on adding custom references, refer to **GetCustomReferences**.

## See also

[IOpcSignatureReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereferenceset)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)