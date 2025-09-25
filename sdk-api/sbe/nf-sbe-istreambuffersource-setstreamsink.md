# IStreamBufferSource::SetStreamSink

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetStreamSink** method sets a pointer to the [Stream Buffer Sink](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-sink-filter) filter, so that the Stream Buffer Source filter can stream data from the sink filter.

## Parameters

### `pIStreamBufferSink` [in]

Pointer to the Stream Buffer Sink filter's [IStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The source filter and the sink filter must be within the same process, but can reside in different filter graphs. If they are in different processes, call [IFileSourceFilter::Load](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesourcefilter-load) with the same file name used in the [IStreamBufferSink::LockProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-lockprofile) method.

Several Stream Buffer Source filters can stream from the same sink filter.

## See also

[IStreamBufferSource Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersource)