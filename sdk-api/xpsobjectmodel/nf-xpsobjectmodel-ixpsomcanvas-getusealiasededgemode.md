# IXpsOMCanvas::GetUseAliasedEdgeMode

## Description

Gets a Boolean value that determines whether the edges of the objects in the canvas are to be rendered using the aliased edge mode.

## Parameters

### `useAliasedEdgeMode` [out, retval]

The Boolean value that determines whether the objects in the canvas are to be rendered using the aliased edge mode.

| Value | Meaning |
| --- | --- |
| **TRUE** | The edges of objects in the canvas are to be rendered without anti-aliasing using the aliased edge mode. This includes any objects in the canvas that have *useAliasedEdgeMode* set to **FALSE**.<br><br>In the document markup, this corresponds to the **RenderOptions.EdgeMode** attribute having a value of **Aliased**. |
| **FALSE** | The edges of objects in the canvas are to be rendered in the default manner.<br><br>In the document markup, this corresponds to the **RenderOptions.EdgeMode** attribute being absent. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *useAliasedEdgeMode* is **NULL**. |

## Remarks

The property that is returned by this method corresponds to the **RenderOptions.EdgeMode** attribute of the **Canvas** element in the document markup.

## See also

[IXpsOMCanvas](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcanvas)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))