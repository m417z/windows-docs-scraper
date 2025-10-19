# IXpsOMCanvas::SetUseAliasedEdgeMode

## Description

Sets the value that determines whether the edges of objects in this canvas will be rendered using the aliased edge mode.

## Parameters

### `useAliasedEdgeMode` [in]

The Boolean value that determines whether the edges of child objects in this canvas will be rendered using the aliased edge mode.

| Value | Meaning |
| --- | --- |
| **TRUE** | The edges of objects in the canvas are to be rendered without anti-aliasing using the aliased edge mode. This includes any objects that have this value set to **FALSE**.<br><br>In the document markup, this corresponds to the **RenderOptions.EdgeMode** attribute having the value of **Aliased**. |
| **FALSE** | The edges of objects in the canvas are to be rendered in the default manner.<br><br>In the document markup, this corresponds to the **RenderOptions.EdgeMode** attribute being absent. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

This property corresponds to the **RenderOptions.EdgeMode** attribute of the **Canvas** element in the document markup.

## See also

[IXpsOMCanvas](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcanvas)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)