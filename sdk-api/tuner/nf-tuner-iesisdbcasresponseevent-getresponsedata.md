# IESIsdbCasResponseEvent::GetResponseData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the response data returned in an [IsdbCasResponse](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent) event.

## Parameters

### `pbData` [out, retval]

Pointer to a buffer that receives the response data. The caller must free this memory after use.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESIsdbCasResponseEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent)