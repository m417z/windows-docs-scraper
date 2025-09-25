# IXpsOMDictionary::Append

## Description

Appends an [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface along with its *key* to the end of the dictionary.

## Parameters

### `key` [in]

The key to be used for this entry.

The string referenced by *key* must be unique in the dictionary.

### `entry` [in]

A pointer to the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface that is to be appended to the dictionary.

A dictionary cannot contain duplicate interface pointers. This parameter must contain an interface pointer that is not already in the dictionary.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *entry* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The interface pointers stored in a dictionary will usually point to interfaces, such as [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) and [IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual), that are derived from the [IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable) interface. To determine the interface type, call the [IXpsOMShareable::GetType](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomshareable-gettype) method.

The figure that follows illustrates how the dictionary is changed by the **Append** method.

![A figure that shows how Append adds an entry to the dictionary](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/dictionary_append.png)

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMShareable](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomshareable)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))