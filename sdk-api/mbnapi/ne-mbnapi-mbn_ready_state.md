# MBN_READY_STATE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_READY_STATE** enumerated type contains values that indicate the readiness of a Mobile Broadband device to engage in cellular network traffic operations.

 These values are returned by the [GetReadyState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getreadystate) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface). For a device with a SIM card, this is to signal that the SIM has been initialized and is ready for access.

## Constants

### `MBN_READY_STATE_OFF:0`

The mobile broadband device stack is off.

### `MBN_READY_STATE_INITIALIZED`

The card and stack is powered up and ready to be used for mobile broadband operations.

### `MBN_READY_STATE_SIM_NOT_INSERTED`

The SIM is not inserted.

### `MBN_READY_STATE_BAD_SIM`

The SIM is invalid (PIN Unblock Key retrials have exceeded the limit).

### `MBN_READY_STATE_FAILURE`

General device failure.

### `MBN_READY_STATE_NOT_ACTIVATED`

The subscription is not activated.

### `MBN_READY_STATE_DEVICE_LOCKED`

The device is locked by a PIN or password which is preventing the device from initializing and registering onto the network. The calling application can call the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of the [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) interface to get the type of PIN needed to be entered to unlock the device.

### `MBN_READY_STATE_DEVICE_BLOCKED`

The device is blocked by a PIN or password which is preventing the device from initializing and registering onto the network. The calling application should call the [Unblock](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpin-unblock) method of the [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) interface to unblock the device.

### `MBN_READY_STATE_NO_ESIM_PROFILE`