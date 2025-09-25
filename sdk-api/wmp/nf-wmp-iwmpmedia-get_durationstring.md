# IWMPMedia::get_durationString

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_durationString** method retrieves a string indicating the duration of the current media item in HH:MM:SS format.

## Parameters

### `pbstrDuration` [out]

Pointer to a **BSTR** containing the duration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If this method is used with a media item other than the one specified in **IWMPCore::get_currentMedia**, it may not contain a valid value. If the media item is less than an hour long, the hours portion of the return value is omitted.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPCore::get_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentmedia)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia::get_duration](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_duration)