# WMIsAvailableOffline function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMIsAvailableOffline** function verifies that an ASF file can be played from a cached copy. If a user plays a file from a network location, part or all of the file may be stored in a cache. If that cached copy exists on the local machine, the user may be able to play the file without being connected to the network.

## Parameters

### `pwszURL` [in]

Wide-character **null**-terminated string containing the URL of the file to be checked.

### `pwszLanguage` [in]

Wide-character **null**-terminated string containing the RFC 1766-compliant language ID specifying which language is desired for playback. This value is only important for files that contain language-based mutual exclusion.

Set to **NULL** if all languages are acceptable.

### `pfIsAvailableOffline` [out]

Pointer to a Boolean value that is set to True if the file is available offline.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | One or both of the input parameters are **NULL**. |

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)