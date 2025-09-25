# IESRequestTunerEvent::GetPriority

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code that indicates the priority of a device request for exclusive access to a tuner and its Conditional Access Services (CAS).

## Parameters

### `pbyPriority` [out, retval]

Gets a 1-byte code that indicates the priority. The code can be any of the following values.

| Value | Meaning |
| --- | --- |
| **0x00** | OPPORTUNISTIC. The device that receives the request should see if the request conflicts with any other tuner usage, including scheduled and live viewing usages. |
| **0x01** | NOTIFY. The device that receives the request should check to see if the request conflicts with any other scheduled usage. If the acquisition conflicts with live viewing, the device should prompt the user before relinquishing access. |
| **0x02-0xFE** | Reserved. |
| **0xFF** | IMMEDIATE. The device that receives the request must release the tuner for the requestor ownership within the next 60 seconds. The requestor can forcibly acquire the tuner after 60 seconds. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESRequestTunerEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesrequesttunerevent)