# IMFSinkWriter::GetStatistics

## Description

Gets statistics about the performance of the sink writer.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of a stream to query, or **MF_SINK_WRITER_ALL_STREAMS**  to query the media sink itself.

### `pStats` [out]

A pointer to an [MF_SINK_WRITER_STATISTICS](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/ns-mfreadwrite-mf_sink_writer_statistics) structure. Before calling the method, set the **cb** member to the size of the structure in bytes. The method fills the structure with statistics from the sink writer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number. |

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)