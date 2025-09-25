# ITACDGroup::get_Queues

## Description

The
**get_Queues** method creates a collection of queues associated with the current ACD group. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateQueues](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itacdgroup-enumeratequeues) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue) interface pointers (queue objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue) interface returned by **ITACDGroup::get_Queues**. The application must call **Release** on the
**ITQueue** interface to free resources associated with it.

## See also

[EnumerateQueues](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itacdgroup-enumeratequeues)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)