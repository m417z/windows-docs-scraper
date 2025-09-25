# IWMPCdromCollection::get_count

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_count** method retrieves the number of available CD and DVD drives on the system.

## Parameters

### `plCount` [out]

Pointer to a **long** containing the count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To retrieve the value of this property, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

DVD drives are counted exactly like CD drives. However, the Windows Media Player ActiveX control only supports DVD functionality for Windows XP or later. Typically, DVD drives can play CD media, but CD drives cannot play DVD media.

**Windows Media Player 10 Mobile:** This method always retrieves a **long** set to 0.

## See also

[IWMPCdromCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromcollection)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)