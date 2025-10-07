# WMCreateStreamForURL function

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCreateStreamForURL** function is implemented by the application to create a COM **IStream** object for a given URL.

## Parameters

*pwszURL* \[in\]

Pointer to a wide-character string containing the URL.

*pfCorrectSource* \[out\]

Pointer to a flag, true will prevent the SDK from trying other source plug-ins for this URL.

*ppStream* \[out\]

Pointer to a pointer to the **IStream** object created by the method.

## Return value

If the function succeeds, it must return S\_OK. If it fails, it must return an appropriate **HRESULT** error code, and \**ppStream* should be set to **NULL**.

## See also

[**Source Plug-ins**](https://learn.microsoft.com/windows/win32/wmformat/source-plug-ins)

