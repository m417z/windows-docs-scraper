# IWMPLibraryServices::getCountByType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getCountByType** method retrieves the count of available libraries of a specified type.

## Parameters

### `wmplt` [in]

[WMPLibraryType](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmplibrarytype) enumeration value that specifies the type of library to count.

### `plCount` [out]

Pointer to a **long** that receives the library count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To obtain a count of the libraries represented by the wmpltRemote value of the **WMPLibraryType** enumeration, the Player control must be running in remote mode. For information about running the Player control in remote mode, see [Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control).

You must initialize the *plCount* variable before passing in its pointer.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPLibraryServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibraryservices)

[WMPLibraryType](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmplibrarytype)