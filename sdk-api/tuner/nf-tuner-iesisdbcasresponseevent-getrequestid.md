# IESIsdbCasResponseEvent::GetRequestId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the request identifier returned in an [IsdbCasResponse](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent) event. The request identifier identifies the request originated by a PBDA media sink device (MSD).

## Parameters

### `pRequestId` [out, retval]

Receives the request identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESIsdbCasResponseEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent)