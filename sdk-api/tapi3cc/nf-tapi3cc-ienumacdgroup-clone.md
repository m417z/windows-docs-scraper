# IEnumACDGroup::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup) interface.

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
[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup) interface returned by **IEnumACDGroup::Clone**. The application must call **Release** on the
**IEnumACDGroup** interface to free resources associated with it.

## See also

[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)