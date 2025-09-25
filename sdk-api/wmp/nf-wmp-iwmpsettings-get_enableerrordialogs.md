# IWMPSettings::get_enableErrorDialogs

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_enableErrorDialogs** method retrieves a value indicating whether error dialog boxes are displayed automatically.

## Parameters

### `pfEnableErrorDialogs` [out]

Pointer to a **VARIANT_BOOL** indicating whether error dialog boxes are displayed automatically. The default is **TRUE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method exhibits specific behavior for remoted instances of the Windows Media Player control. For more information, see [Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control).

## See also

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::put_enableErrorDialogs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_enableerrordialogs)