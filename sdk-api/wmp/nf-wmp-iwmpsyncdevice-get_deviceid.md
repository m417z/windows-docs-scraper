# IWMPSyncDevice::get_deviceId

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_deviceId** method retrieves the device identifier string.

## Parameters

### `pbstrDeviceId` [out]

Address of a **BSTR** variable that receives a string containing the device identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

The device identifier is the serial number for the device. This value is not guaranteed to be unique for mass storage devices. However, it is unlikely that a particular user will encounter duplicate serial numbers.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[IWMPSyncDevice::get_partnershipIndex](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_partnershipindex)

[Retrieving Device Attributes](https://learn.microsoft.com/windows/desktop/WMP/retrieving-device-attributes)