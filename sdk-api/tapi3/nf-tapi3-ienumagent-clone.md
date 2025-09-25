# IEnumAgent::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagent) interface.

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
[IEnumAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagent) interface returned by **IEnumAgent::Clone**. The application must call **Release** on the
**IEnumAgent** interface to free resources associated with it.

## See also

[IEnumAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagent)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)