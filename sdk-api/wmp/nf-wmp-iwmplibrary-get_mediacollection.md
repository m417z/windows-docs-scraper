# IWMPLibrary::get_mediaCollection

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_mediaCollection** method retrieves a pointer to the **IWMPMediaCollection** interface for the current library.

## Parameters

### `ppIWMPMediaCollection` [out]

Address of a variable that receives a pointer to the **IWMPMediaCollection** interface for the current library.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPLibrary Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibrary)

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)