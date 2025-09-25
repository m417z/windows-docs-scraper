# WM_CLIENT_PROPERTIES_EX structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_CLIENT_PROPERTIES_EX** structure holds extended client information.

## Members

### `cbSize`

**DWORD** containing the size of the structure.

### `pwszIPAddress`

String containing the client's IP address in dot notation (for example, "192.168.10.2").

### `pwszPort`

String containing the client's port number.

### `pwszDNSName`

String containing the client's name on the domain name server (DNS), if known.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)

[WM_CLIENT_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_properties)