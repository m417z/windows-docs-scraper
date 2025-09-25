# IEnumQueue::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue) interface returned by **IEnumQueue::Clone**. The application must call **Release** on the
**IEnumQueue** interface to free resources associated with it.

## See also

[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue)