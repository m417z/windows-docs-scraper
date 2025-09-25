# IWMReaderStreamClock::SetTimer

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetTimer** method sets a timer on the clock.

## Parameters

### `cnsWhen` [in]

Specifies the time at which the reader notifies the [OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback, in 100-nanosecond units.

### `pvParam` [in]

Specifies a pointer to the timer context parameters that are returned in the **OnStatus** callback.

### `pdwTimerId` [out]

Pointer to a **DWORD** containing the timer identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pdwTimerId* is **NULL**. |
| **E_OUTOFMEMORY** | Not enough available memory. |

## Remarks

The application must execute [IWMReader::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open), and successfully receive a WMT_OPENED status notification to its [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method, before it creates any timers.

All timers are automatically terminated when the application stops the reader. When a timer expires, the following happens:

* The **OnStatus** method is called with WMT_TIMER, as the [WMT_STATUS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_status) enumeration type
* The parameter *hr* is set to S_OK
* *pValue* is set to the TimerID
* *pvContext* is set to the *pvParam* pointer that is specified in this method

## See also

[IWMReaderStreamClock Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderstreamclock)

[IWMReaderStreamClock::GetTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderstreamclock-gettime)