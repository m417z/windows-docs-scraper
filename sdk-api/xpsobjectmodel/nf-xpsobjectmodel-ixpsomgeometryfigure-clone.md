# IXpsOMGeometryFigure::Clone

## Description

Makes a deep copy of the interface.

## Parameters

### `geometryFigure` [out, retval]

A pointer to the copy of the interface.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to perform this operation. |
| **E_POINTER** | *geometryFigure* is **NULL**. |

## Remarks

The owner of the copy is **NULL**.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)