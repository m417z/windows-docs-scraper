# IWMPMedia2::get_error

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_error** method retrieves a pointer to an **IWMPErrorItem** interface if the media item has an error condition.

## Parameters

### `ppIWMPErrorItem` [out]

Pointer to a pointer to an **IWMPErrorItem** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the media item cannot be played, this property retrieves an **IWMPErrorItem** interface that contains information about the problem encountered.

## See also

[IWMPErrorItem Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperroritem)

[IWMPMedia2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia2)