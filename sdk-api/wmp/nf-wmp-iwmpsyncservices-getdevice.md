# IWMPSyncServices::getDevice

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getDevice** method retrieves a pointer to a device interface.

## Parameters

### `lIndex` [in]

**long** that contains the index of the device to retrieve. Device indexes are zero-based.

### `ppDevice` [out]

Pointer to a pointer to an **IWMPSyncDevice** interface that represents the device having the specified index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncservices)