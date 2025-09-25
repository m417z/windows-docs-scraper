# IXpsSignatureCollection::GetAt

## Description

Gets an [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface pointer from a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index of the [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface pointer to be obtained.

### `signature` [out, retval]

The [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface pointer at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)