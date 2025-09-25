# IXpsSignatureBlockCollection::RemoveAt

## Description

Removes and releases an [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) interface pointer from a specified location in the collection.

## Parameters

### `index`

The zero-based index in the collection from which an [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) interface pointer is to be removed and released.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

From the location specified by *index*, this method releases the interface referenced by an [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) pointer. The method then compacts the collection by reducing by 1 the index of each pointer subsequent to *index*. For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

Removing a signature block from the collection removes from the package the SignatureDefinitions part and relationship that correspond to that signature block. This removal breaks existing signatures. In addition, the SignatureDefinitions part name is removed from the list of required XPS parts, which prevents new signatures from including the removed signature block.

An interface that has been removed from a collection is no longer valid. If an application retains a pointer to the interface and tries to call one of its methods, the method will return **XPS_E_OBJECT_DETACHED**.

## See also

[IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock)

[IXpsSignatureBlockCollection](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblockcollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)