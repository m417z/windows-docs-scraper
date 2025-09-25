# IWMReader::Start

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Start** method causes the reader object to start reading from the specified starting time offset. As data is read, it is passed to the application through the application's [IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample) callback method.

## Parameters

### `cnsStart` [in]

Time within the file at which to start reading, in 100-nanosecond units. If *cnsStart* is set to WM_START_CURRENTPOSITION, playback starts from the current position.

### `cnsDuration` [in]

Duration of the read in 100-nanosecond units, or zero to read to the end of the file.

### `fRate` [in]

Playback speed. Normal speed is 1.0. Higher numbers cause faster playback, and numbers less than zero indicate reverse rate (rewinding). The valid ranges are 1.0 through 10.0, and -1.0 through -10.0.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is passed back to the **OnSample** method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **NS_E_INVALID_REQUEST** | The value for *fRate* is not within the valid ranges, or the file is not seekable and a non-zero start position has been specified. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

This method sends a WMT_STARTED status notification to the application's **IWMReaderCallback::OnStatus** function.

To change the rate but not the current file position, use the **Start** method with the WM_START_CURRENTPOSITION value.

Any call to **Start** while paused is treated as a *seek* through the file, and incurs a buffering penalty from network files. This is true even for calls to **Start** with the WM_START_CURRENTPOSITION value. To continue playing from the current paused position with no buffering penalty, call **Resume**.

If the application is providing the clock (by calling [IWMReaderAdvanced::SetUserProvidedClock](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setuserprovidedclock)), it should usually set the *cnsDuration* parameter to zero. If the application specifies a non-zero value, then it must call the [IWMReaderAdvanced::DeliverTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-delivertime) method exactly once, and the value passed to **DeliverTime** must be either the stop time or `(QWORD)-1`. The reader object will then deliver samples up to the specified duration.

This method is very similar to the [IWMReaderAdvanced2::StartAtMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-startatmarker) method, but that method uses a [marker](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) instead of a start time.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)

[IWMReader::Stop](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-stop)

[IWMReaderCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback)