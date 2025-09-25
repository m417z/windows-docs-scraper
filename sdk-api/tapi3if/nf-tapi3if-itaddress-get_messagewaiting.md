# ITAddress::get_MessageWaiting

## Description

The
**get_MessageWaiting** method determines if the address has a message waiting.

## Parameters

### `pfMessageWaiting` [out]

If VARIANT_TRUE is returned, a message is waiting; if VARIANT_FALSE is returned, no message is waiting.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pfMessageWaiting* parameter is not a valid pointer. |

## Remarks

In TAPI 2.*x*, this maps to the flag LINEDEVSTATUSFLAGS_MSGWAIT being set or not in the member *dwDevStatusFlags* from the structure
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus).

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[put_MessageWaiting](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-put_messagewaiting)