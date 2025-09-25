# IESRequestTunerEvent::GetEstimatedTime

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a value indicating the amount of time that a device estimates it needs exclusive access to a tuner and its Conditional Access Services (CAS).

## Parameters

### `pdwEstimatedTime` [out, retval]

Gets the estimated time that exclusive access is needed, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESRequestTunerEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesrequesttunerevent)