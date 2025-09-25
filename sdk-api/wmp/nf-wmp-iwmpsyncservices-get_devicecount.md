# IWMPSyncServices::get_deviceCount

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_deviceCount** method retrieves the number of available devices.

## Parameters

### `plCount` [out]

Pointer to a **long** that contains the device count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

This method may return devices that have been connected previously, but that do not have a partnership established. Therefore, the list of returned devices does not represent a list of devices with partnerships.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncservices)