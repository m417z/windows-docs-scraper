# IWMPCdrom::get_driveSpecifier

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_driveSpecifier** method retrieves the CD or DVD drive letter.

## Parameters

### `pbstrDrive` [out]

Pointer to a **BSTR** containing the drive.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Typically, DVD drives can play CD media, but CD drives cannot play DVD media.

This method retrieves a drive letter for a zero-based drive index within the range retrieved using the **IWMPCdromCollection::get_count** method. The value retrieved takes the form *X*:, where *X* represents the drive letter.

To retrieve the value of this property, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdrom Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdrom)

[IWMPCdromCollection::get_count](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromcollection-get_count)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)