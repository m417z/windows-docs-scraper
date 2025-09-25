# IWMPLibrary::get_name

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_name** method retrieves the display name of the current library.

## Parameters

### `pbstrName` [out]

Pointer to a string containing the name of the current library.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPLibrary Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibrary)

[IWMPLibrary::get_type](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmplibrary-get_type)