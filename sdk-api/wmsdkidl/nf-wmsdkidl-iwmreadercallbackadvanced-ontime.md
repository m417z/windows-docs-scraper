# IWMReaderCallbackAdvanced::OnTime

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnTime** method notifies the application of the clock time the reader is working to. This method is used when a user-provided clock has been specified.

## Parameters

### `cnsCurrentTime` [in]

**QWORD** containing the current time in 100-nanosecond units.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) method.

## Return value

To use this method, you must implement it in your application. You can return whatever **HRESULT** error codes are appropriate to your implementation. For more information about the **HRESULT** error codes included for use by the Windows Media Format SDK, see [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes).

## Remarks

There are two cases in which callbacks indicating what the reader registers as the current elapsed time must be received by an application. The first case occurs when there are gaps in an ASF file (for example, no audio for 10 seconds). The **OnTime** method continues to be called, while [OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample) does not. In the second case, if the application is driving the clock, the reader calls **OnTime** after it has delivered all the data up to the point requested by the application in a call to [IWMReaderAdvanced::DeliverTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-delivertime).

## See also

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)