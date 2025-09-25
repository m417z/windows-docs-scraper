# IXpsOMGeometryFigure::SetIsFilled

## Description

Sets a value that indicates whether the figure is filled.

## Parameters

### `isFilled` [in]

The value to be set.

| Value | Meaning |
| --- | --- |
| **TRUE** | The figure is filled by a brush. |
| **FALSE** | The figure is not filled. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

In the document markup, the value returned in *isFilled* corresponds to that of the **IsFilled** attribute of the **PathFigure** element.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)