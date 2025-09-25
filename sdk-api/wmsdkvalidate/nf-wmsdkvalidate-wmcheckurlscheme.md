# WMCheckURLScheme function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCheckURLScheme** function examines a network protocol and compares it to an internal list of supported schemes. If you are writing an application that can handle many different network protocols, you can use this function to ascertain quickly whether a network address can be handled using the methods of the Windows Media Format SDK.

## Parameters

### `pwszURLScheme` [in]

A wide-character null-terminated string containing a network protocol designation, such as "http".

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **NS_E_INVALID_NAME** | The URL passed does not conform to any of the commonly used schemes. |

## Remarks

This function cannot report with absolute certainty whether a particular URL can be handled, as this cannot be determined until the URL is opened.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)