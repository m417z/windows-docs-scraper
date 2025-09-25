# MBN_PIN_STATE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PIN_STATE** enumerated type indicates the current PIN state of the Mobile Broadband device.

## Constants

### `MBN_PIN_STATE_NONE:0`

Indicates that no PIN is currently required.

This state can occur when the device does not require a PIN. It can also occur after repeated PIN entry attempts have exhausted the allowable quota and the device does not allow the PIN to be unblocked programmatically

### `MBN_PIN_STATE_ENTER`

Indicates that the device is currently locked and requires a PIN to be entered to unlock it The caller can unlock the device by calling the [Enter](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-enter) method of the [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface.

### `MBN_PIN_STATE_UNBLOCK`

Indicates that the device is in a PIN blocked state and that the PIN needs to be unblocked using the corresponding PIN Unblock Key (PUK). The caller can unlock the device by calling the [Unblock](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-unblock) method of the [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface.

This state can occur after repeated PIN entry attempts have exhausted the allowable quota.