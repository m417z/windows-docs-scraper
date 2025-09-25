# IWMReaderAdvanced::GetStatistics

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStatistics** method retrieves the current reader statistics.

## Parameters

### `pStatistics` [in, out]

Pointer to a [WM_READER_STATISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_reader_statistics) structure.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pStatistics* is **NULL**, or the **cbSize** member of *pStatistics* is not set to the size of **WM_READER_STATISTICS**. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for an internal object. |
| **NS_E_INVALID_REQUEST** | The reader object has not opened a file yet. |

## Remarks

The **WM_READER_STATISTICS** structure must be supplied by the application. The **cbSize** data member must be set before the structure is passed to the method. The rest of the members will be set by this method.

As with any method, too many calls can affect performance. The actual performance impact is machine-dependent. Using the **GetStatistics** method for each sample is not recommended. The Microsoft Windows Media Encoder pulls the data once per second, which results in a manageable amount of data being passed.

The **GetStatistics** method is not recommended for a callback method like [IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample). In general, such calls have the potential to lead to deadlocks.

To determine the connection bandwidth before receiving a sample, the [IWMReaderNetworkConfig::GetConnectionBandwidth](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getconnectionbandwidth) method is the recommended method. The **GetStatistics** method has more overhead.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)