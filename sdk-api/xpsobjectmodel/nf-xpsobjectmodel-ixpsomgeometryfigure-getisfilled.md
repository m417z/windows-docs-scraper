# IXpsOMGeometryFigure::GetIsFilled

## Description

Gets a value that indicates whether the figure is filled.

## Parameters

### `isFilled` [out, retval]

The Boolean value that indicates whether the figure is filled.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The figure is filled by a brush. |
| ****FALSE**** | The figure is not filled. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *isFilled* is **NULL**. |

## Remarks

This value corresponds to that of the **IsFilled** attribute of the **PathFigure** element in the document markup.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)