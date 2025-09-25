# ITACDGroup::EnumerateQueues

## Description

The
**EnumerateQueues** method enumerates queues currently on the ACD group. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Queues](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itacdgroup-get_queues) method.

## Parameters

### `ppEnumQueue` [out]

Pointer to
[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppEnumQueue* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue) interface returned by **ITACDGroup::EnumerateQueues**. The application must call **Release** on the
**IEnumQueue** interface to free resources associated with it.

## See also

[IEnumQueue](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumqueue)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)

[get_Queues](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itacdgroup-get_queues)