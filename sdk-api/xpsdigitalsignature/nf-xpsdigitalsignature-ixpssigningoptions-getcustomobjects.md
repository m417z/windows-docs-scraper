# IXpsSigningOptions::GetCustomObjects

## Description

Gets a pointer to an [IOpcSignatureCustomObjectSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobjectset) interface that contains a set of signature custom objects.

## Parameters

### `customObjectSet` [out, retval]

A pointer to an [IOpcSignatureCustomObjectSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobjectset) interface that contains a set of signature custom objects.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The custom object set that this method returns is empty. To add a custom object to this set, call the [Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturecustomobjectset-create) method of the interface that is returned in *customObjectSet*.

If a custom object must be signed, a reference to that object must be added to the custom object set. For information on adding custom references, refer to [GetCustomReferences](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssigningoptions-getcustomreferences).

## See also

[GetCustomReferences](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssigningoptions-getcustomreferences)

[IOpcSignatureCustomObjectSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturecustomobjectset)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)