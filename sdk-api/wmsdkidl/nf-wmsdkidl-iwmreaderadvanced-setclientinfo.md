# IWMReaderAdvanced::SetClientInfo

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetClientInfo** method sets client-side information used for logging. Use this method to specify information about the client that the reader object sends to the server for logging. If the application does not call this method, the reader object uses default values.

## Parameters

### `pClientInfo` [in]

Pointer to a [WM_READER_CLIENTINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_reader_clientinfo) structure allocated by the caller, which contains information about the client.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. The **cbSize** member must be set, and the string values must not exceed 1024 characters. |

## Remarks

Initialize the **WM_READER_CLIENTINFO** structure before calling this method. Always set the **cbSize** member equal to the size of the structure, and set any unused fields to zero.

```cpp

WM_READER_CLIENTINFO info;
ZeroMemory(&info, sizeof(WM_READER_CLIENTINFO));
info.cbSize = sizeof(WM_READER_CLIENTINFO);

// Set other fields (not shown).

hr = pReaderAdvanced->SetClientInfo( &info );

```

## See also

[Client Logging](https://learn.microsoft.com/windows/desktop/wmformat/client)

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)