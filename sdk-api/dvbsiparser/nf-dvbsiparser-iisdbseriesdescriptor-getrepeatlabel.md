# IIsdbSeriesDescriptor::GetRepeatLabel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a label that identifies a series repeat from an Integrated Services Digital Broadcasting (ISDB) series descriptor.

## Parameters

### `pbVal` [out]

Receives the repeat label. If this label is zero, the series is an original broadcast.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSeriesDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbseriesdescriptor)