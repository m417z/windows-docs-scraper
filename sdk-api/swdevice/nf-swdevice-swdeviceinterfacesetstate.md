# SwDeviceInterfaceSetState function

## Description

Enables or disables a device interface for a software device.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to the software device to register a device interface for.

### `pszDeviceInterfaceId` [in]

A string that identifies the interface to enable or disable.

### `fEnabled` [in]

A Boolean value that indicates whether to either enable or disable the interface. **TRUE** to enable; **FALSE** to disable.

## Return value

S_OK is returned if **SwDeviceInterfaceSetState** successfully enabled or disabled the interface; otherwise, an appropriate error value.

## Remarks

You can call **SwDeviceInterfaceSetState** only after the operating system has called your client app's [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function to notify the client app that device enumeration completed.

You can only use **SwDeviceInterfaceSetState** to manage interfaces that were previously registered with [SwDeviceInterfaceRegister](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdeviceinterfaceregister) against the software device that *hSwDevice* represents.

Client apps use **SwDeviceInterfaceSetState** to manage the state that they want the interface to have. The software device changes the actual interface state as needed. For example, a client app disables and re-enables the interface if the device is re-enumerated for any reason. The state always tries to reflect the client app’s required state.