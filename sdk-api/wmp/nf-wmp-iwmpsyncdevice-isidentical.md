# IWMPSyncDevice::isIdentical

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **isIdentical** method compares the current device to the specified device and retrieves a value indicating whether they are the same device.

## Parameters

### `pDevice` [in]

Pointer to an **IWMPSyncDevice** interface that represents the device to which to compare the current device.

### `pvbool` [out]

Pointer to a **VARIANT_BOOL** that indicates the result of the comparison.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

This method is useful in event handlers that provide an **IWMPSyncDevice** pointer as a parameter.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[Showing Synchronization Progress](https://learn.microsoft.com/windows/desktop/WMP/showing-synchronization-progress)