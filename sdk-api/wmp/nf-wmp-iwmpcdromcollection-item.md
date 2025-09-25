# IWMPCdromCollection::item

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **item** method retrieves a pointer to an **IWMPCdrom** interface at the given index.

## Parameters

### `lIndex` [in]

**long** containing the index.

### `ppItem` [out]

Pointer to a pointer to an **IWMPCdrom** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To use this method, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPCdrom Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdrom)

[IWMPCdromCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromcollection)

[IWMPCdromCollection::get_count](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromcollection-get_count)

[IWMPCdromCollection::get_driveSpecifier](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdrom-get_drivespecifier)

[IWMPPlaylist::get_name](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-get_name)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)