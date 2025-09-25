# IXpsOMVisualBrush::Clone

## Description

Makes a deep copy of the interface.

## Parameters

### `visualBrush` [out, retval]

A pointer to the copy of the interface.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to perform this operation. |
| **E_POINTER** | *visualBrush* is **NULL**. |

## Remarks

This method does not update the resource pointers in the new [IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush) interface.

## See also

[IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)