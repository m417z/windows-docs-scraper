# IWMPLibrarySharingServices::showLibrarySharing

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **showLibrarySharing** method displays the Windows Media Player **Library Sharing** dialog box.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **Library Sharing** dialog box enables the user to configure library sharing. Users can access this dialog box by pointing to **Tools**, then clicking **Options**, and then clicking **Configure Media Sharing** in the Windows Media Player menu; or by clicking the arrow below the **Library** tab and then clicking **Library Sharing**.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPLibrarySharingServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibrarysharingservices)