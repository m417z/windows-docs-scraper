# IXpsOMRemoteDictionaryResource::GetDictionary

## Description

Gets a pointer to the [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface of the remote dictionary that is associated with this resource.

## Parameters

### `dictionary` [out, retval]

A pointer to the [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface of the dictionary that is associated with this resource.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *dictionary* is **NULL**. |

## Remarks

After loading and parsing the resource into the XPS OM, this method might return an error that applies to another resource. This occurs because all of the relationships are parsed when a resource is loaded.

## See also

[IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))