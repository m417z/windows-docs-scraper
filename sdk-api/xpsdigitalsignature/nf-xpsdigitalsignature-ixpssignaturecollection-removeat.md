# IXpsSignatureCollection::RemoveAt

## Description

Removes and releases an [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface pointer from a specified location in the collection.

## Parameters

### `index`

The zero-based index in the collection from which an [IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature) interface pointer is to be removed and released.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

This method releases an interface referenced by the pointer at the location specified by *index*. After releasing the interface, this method compacts the collection by reducing by 1 the index of each pointer subsequent to *index*.

Once an interface has been removed from a collection, it is no longer valid. If an application retains a pointer to the interface that was removed and tries to call one of its methods, the method will return **E_UNEXPECTED**.

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)