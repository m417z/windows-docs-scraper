# IXpsOMDictionary::InsertAt

## Description

Inserts an [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface at a specified location in the dictionary and sets the key to identify the interface.

## Parameters

### `index` [in]

The zero-based index in the dictionary where the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface is to be inserted.

### `key` [in]

The key to be used to identify the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface in the dictionary.

The string referenced by *key* must be unique in the dictionary.

### `entry` [in]

The [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface pointer to be inserted at the location specified by *index*.

A dictionary cannot contain duplicate interface pointers. This parameter must contain an interface pointer that is not already in the dictionary.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *entry* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The interface pointers stored in the dictionary will usually be pointers to interfaces, such as [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) and [IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual), that are derived from the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface. To determine the interface type, call the [IXpsOMShareable::GetType](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomshareable-gettype) method.

At the location specified by *index*, this method inserts the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface pointer and sets the key; the interface pointer and key are passed in *value* and *key*, respectively. Before *value* and *key* are inserted, the interface pointer and the key at this and all subsequent locations are moved up by one index.

The figure that follows illustrates how the dictionary is changed by the **InsertAt** method.

![A figure that shows how InsertAt adds an entry to the dictionary](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dictionary_insertat.png)

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))