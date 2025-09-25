# IXpsOMPageReference::Clone

## Description

Makes a deep copy of the interface.

## Parameters

### `pageReference` [out, retval]

A pointer to the copy of the interface.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to perform this operation. |
| **E_POINTER** | *pageReference* is **NULL**. |

## Remarks

This method does not update the resource pointers in the new [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface.

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)