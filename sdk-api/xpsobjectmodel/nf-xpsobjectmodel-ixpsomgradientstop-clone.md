# IXpsOMGradientStop::Clone

## Description

Makes a deep copy of the [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface.

## Parameters

### `gradientStop` [out, retval]

A pointer to the copy of the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to perform this operation. |
| **E_POINTER** | *gradientStop* is **NULL**. |

## Remarks

The owner of the new interface is **NULL**.

This method does not update any of the resource pointers in the [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface returned in *gradientStop*.

## See also

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))