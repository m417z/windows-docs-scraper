# SBE_PIN_DATA structure

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP Service Pack 2 only.

The **STREAMBUFFER_ATTRIBUTE** structure contains performance data for the stream buffer filters.

## Members

### `cDataBytes`

Total sample payload, in bytes.

### `cSamplesProcessed`

Number of samples processed.

### `cDiscontinuities`

Number of discontinuities. See [IMediaSample::SetDiscontinuity](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-setdiscontinuity).

### `cSyncPoints`

Number of synchronization points. See [IMediaSample::SetSyncPoint](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-setsyncpoint).

### `cTimestamps`

Number of time stamps.

## See also

[IStreamBufferDataCounters::GetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferdatacounters-getdata)

[Stream Buffer Engine Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-structures)