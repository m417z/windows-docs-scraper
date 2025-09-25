# IIsdbSeriesDescriptor::GetExpireDate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a series expiration date from an Integrated Services Digital Broadcasting (ISDB) series descriptor.

## Parameters

### `pfValid` [out]

Receives a flag that indicates whether the series expiration date in the descriptor expire_date field is valid.

### `pmdtVal` [out]

Receives the date and time when the series expires.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSeriesDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbseriesdescriptor)