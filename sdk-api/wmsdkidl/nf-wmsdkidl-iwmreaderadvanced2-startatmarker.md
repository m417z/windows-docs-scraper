# IWMReaderAdvanced2::StartAtMarker

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **StartAtMarker** method starts the reader from a specified [marker](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary).

## Parameters

### `wMarkerIndex` [in]

**WORD** containing the marker index.

### `cnsDuration` [in]

Specifies the duration, in 100-nanosecond units.

### `fRate` [in]

Floating point number indicating rate. Normal-speed playback is 1.0; higher numbers cause faster playback. Numbers less than zero indicate reverse rate (rewinding). The valid range is 1.0 through 10.0, and -1.0 through -10.0.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **NS_E_INVALID_REQUEST** | The value for *fRate* is not within the valid ranges. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

This method is very similar to [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start). The difference is that this method uses a marker index but **IWMReader::Start** uses a start time.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[Markers](https://learn.microsoft.com/windows/desktop/wmformat/markers)

[Using Markers](https://learn.microsoft.com/windows/desktop/wmformat/using-markers)