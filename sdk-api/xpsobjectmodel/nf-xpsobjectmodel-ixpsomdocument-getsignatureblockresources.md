# IXpsOMDocument::GetSignatureBlockResources

## Description

Gets a pointer to the [IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection) interface, which refers to a collection of the document's digital signature block resources.

## Parameters

### `signatureBlockResources` [out, retval]

A pointer to the [IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection) interface, which refers to a collection of the document's digital signature block resources. If the document does not contain any signature block resources, the **IXpsOMSignatureBlockResourceCollection** interface will be empty.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *signatureBlockResources* is **NULL**. |

## Remarks

After loading and parsing the resource into the XPS OM, this method might return an error that applies to another resource. This occurs because all of the relationships are parsed when a resource is loaded.

## See also

[IXpsOMDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocument)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))