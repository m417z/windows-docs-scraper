# IWMPSettings::get_baseURL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_baseURL** method retrieves the base URL used for relative path resolution with URL script commands that are embedded in digital media content.

## Parameters

### `pbstrBaseURL` [out]

Pointer to a **BSTR** containing the base URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method retrieves the base HTTP URL that is passed as the command parameter by the **ScriptCommand** event. The base URL is concatenated with the relative URL as follows:

1. A trailing forward slash (/) is added to the value retrieved by the **get_baseURL** method.
1. A leading period, backward slash, or forward slash character (., \\, and /) is deleted from the relative URL.
1. The relative URL is added to the end of the base URL.
1. All slash characters in the resulting fully qualified URL are pointed in the same direction (converted to forward or backward slashes) based on the direction of the first slash character encountered in the new URL.

> [!NOTE]
> The Windows Media Player control does not support the use of two periods (..) in the relative URL to indicate the parent of the current location.

**Windows Media Player 10 Mobile:** This method always retrieves a `BSTR` containing an empty string.

## See also

[IWMPEvents::ScriptCommand](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-scriptcommand)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::put_baseURL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_baseurl)