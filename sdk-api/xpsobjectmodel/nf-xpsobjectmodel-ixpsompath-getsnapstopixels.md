# IXpsOMPath::GetSnapsToPixels

## Description

Gets a Boolean value that indicates whether the path is to be snapped to device pixels when the path is rendered.

## Parameters

### `snapsToPixels` [out, retval]

A Boolean value that indicates whether the path is to be snapped to device pixels when the path is rendered. The following table describes the values possible for this parameter.

| Value | Meaning |
| --- | --- |
| **TRUE** | The path is to be snapped to device pixels. |
| **FALSE** | The path is not to be snapped to device pixels. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *snapsToPixels* is **NULL**. |

## Remarks

The value returned by **GetSnapsToPixels** corresponds to the **SnapsToDevicePixels** element in the document markup.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))