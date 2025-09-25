# IWMPErrorItem::get_errorCode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_errorCode** method retrieves the current error code.

## Parameters

### `phr` [out]

Pointer to a **long** containing the error code.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You should set a **VARIANT_BOOL** to **FALSE** and pass it into **IWMPSettings::put_enableErrorDialogs** if you choose to display custom error messages.

## See also

[IWMPErrorItem Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperroritem)

[IWMPSettings::put_enableErrorDialogs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_enableerrordialogs)