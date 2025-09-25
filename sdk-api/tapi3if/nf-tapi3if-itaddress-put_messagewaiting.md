# ITAddress::put_MessageWaiting

## Description

The
**put_MessageWaiting** method sets the status of the message waiting on the address.

## Parameters

### `fMessageWaiting` [in]

Status of message waiting to be set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *fMessageWaiting* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

For programmers familiar with TAPI 2.*x:* This method turns on and off the flag LINEDEVSTATUSFLAGS_MSGWAIT in the **dwDevStatusFlags** member of the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure by calling
[lineSetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetlinedevstatus).

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[get_MessageWaiting](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_messagewaiting)

[lineSetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetlinedevstatus)