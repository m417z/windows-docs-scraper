# IWMReaderAdvanced::SetUserProvidedClock

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetUserProvidedClock** method specifies whether a clock provided by the application is to be used.

## Parameters

### `fUserClock` [in]

Boolean value that is True if an application-provided clock is to be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The reader is not properly configured to handle this request. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory. |
| **E_FAIL** | Unable to set an internal event. |

## Remarks

In some cases, an application built on this SDK requires the clock to be driven by the application rather than by real time. This is true, for example, if the application reads from a file at a rate faster than it takes to play the file. User-provided clocks are only supported when the source file is a local file.

This method can fail if the current source does not support user-provided clocks. To drive a clock, an application must call [DeliverTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-delivertime), and then wait for [IWMReaderCallbackAdvanced::OnTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-ontime) to reach the time specified.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetUserProvidedClock](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getuserprovidedclock)