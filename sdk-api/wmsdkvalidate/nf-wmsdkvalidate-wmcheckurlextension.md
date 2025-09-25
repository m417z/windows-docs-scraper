# WMCheckURLExtension function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCheckURLExtension** function examines the file name extension in the URL or file name that is passed in as an argument. The extension is compared to a list of supported file types in an attempt to determine whether the file can be opened by the objects of this SDK.

If you are writing an application that can handle many different file types, you can use this function to try to quickly determine whether the file can be read using objects of the Windows Media Format SDK.

## Parameters

### `pwszURL` [in]

A wide-character **null**-terminated string containing a file name or URL.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded, and the file extension is supported. This result does not indicate verification of the contents of the file, just the extension. |
| **NS_E_INVALID_NAME** | The URL passed is not of a type supported by the objects of the Windows Media Format SDK. |
| **E_INVALIDARG** | *pwszURL* is **NULL**. |

## Remarks

This function cannot report with absolute certainty whether a particular URL can be handled, as this cannot be determined until the URL is opened.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)