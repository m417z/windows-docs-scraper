# IWMReaderAdvanced::DeliverTime

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DeliverTime** method provides the reader with a clock time. Use this method only when the application is providing the clock.

## Parameters

### `cnsTime` [in]

The time, in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Before making the first call to this method, call the [IWMReaderAdvanced::SetUserProvidedClock](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setuserprovidedclock) method with the value **TRUE**, to specify that the application is providing the clock. Otherwise, the **DeliverTime** method returns E_UNEXPECTED.

After **DeliverTime** is called, the reader reads data as fast as possible until it reaches the specified time. When the reader reaches that time, it calls [IWMReaderCallbackAdvanced::OnTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-ontime), and then sends samples to the callback.

In general, the value of *cnsTime* should increase each time the method is called (that is, the clock should run forward). However, sometimes it may be possible to pass a smaller value. The **DeliverTime** method is asynchronous, meaning the reader object reads the data on another thread. The application can specify a smaller time value only if the reader object has not reached that point in the file. For example, if the application calls **DeliverTime** with the value 100 seconds, and immediately calls it again with the value 50 seconds, the call would probably succeed, because the reader object will not reach the 50-second point in the file. However, you cannot be sure the call will succeed in this case, because the application does not control the reader's thread.

## See also

[Broadcasting ASF Data](https://learn.microsoft.com/windows/desktop/wmformat/broadcasting-asf-data)

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)