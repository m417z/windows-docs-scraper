# IESRequestTunerEvent::GetReason

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code that indicates the reason a device is requesting exclusive access to a tuner and its Conditional Access Services (CAS).

## Parameters

### `pbyReason` [out, retval]

Gets a 1-byte code that indicates the reason for the request. The code can be any of the following values.

| Value | Meaning |
| --- | --- |
| **0x00** | Unspecified. |
| **0x01** | The requesting device needs the tuner to download an internal update, such as new firmware. |
| **[Other]** | Reserved. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESRequestTunerEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesrequesttunerevent)