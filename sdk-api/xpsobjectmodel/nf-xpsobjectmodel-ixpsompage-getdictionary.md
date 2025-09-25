# IXpsOMPage::GetDictionary

## Description

Gets a pointer to the resolved [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface that is associated with this page.

## Parameters

### `resourceDictionary` [out, retval]

A pointer to the resolved [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface that is associated with this page.

The value that is returned in this parameter depends on which method has most recently been called to set the dictionary.

| Most recent method called | Object that is returned in *resourceDictionary* |
| --- | --- |
| [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) | The local dictionary resource that is set by [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal). |
| [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) | The shared dictionary in the dictionary resource that is set by [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource). |
| Neither [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) nor [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *resourceDictionary* is **NULL**. |
| **XPS_E_LOOKUP_INVALID_TYPE** | The lookup key name set by [SetStrokeBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlookup) references an object that is not a brush. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the lookup value.<br><br>No object could be found with a key name that matched the value passed in *lookup*. |

## Remarks

Whether the dictionary is local or is contained within a remote dictionary resource, this method returns an [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface pointer. [GetOwner](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomdictionary-getowner) determines whether the dictionary is remote.

If a page contains a remote dictionary, **GetDictionary** will deserialize the dictionary. If the page contains a remote dictionary that is not valid, **GetDictionary** might return a deserialization error code.

After loading and parsing the resource into the XPS OM, this method might return an error that applies to another resource. This occurs because all of the relationships are parsed when a resource is loaded.

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))