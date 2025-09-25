# ITACDGroupEvent::get_Group

## Description

The
**get_Group** method gets the ITACDGroup interface pointer for the group on which the event occurred.

## Parameters

### `ppGroup` [out]

Pointer to
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface on which the event occurred.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppGroup* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface returned by **ITACDGroupEvent::get_Group**. The application must call **Release** on the
**ITACDGroup** interface to free resources associated with it.

## See also

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)

[ITACDGroupEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroupevent)