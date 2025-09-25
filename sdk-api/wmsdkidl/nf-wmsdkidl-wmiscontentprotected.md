# WMIsContentProtected function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMIsContentProtected** function checks a file for DRM-protected content. This function is a shortcut so that your application can quickly identify protected files.

## Parameters

### `pwszFileName` [in]

Pointer to a wide-character **null**-terminated string containing the name of the file to check for DRM-protected content.

### `pfIsProtected` [out]

Pointer to a Boolean value that is set to True on function return if the file contains DRM-protected content.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | One or both of the parameters are **NULL**. |
| **S_FALSE** | The content is unprotected. |

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)