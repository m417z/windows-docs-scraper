# SW_DEVICE_CREATE_CALLBACK callback function

## Description

Provides a device with backing in the registry and allows the caller to then make calls to Software Device API functions with the *hSwDevice* handle.

## Parameters

### `hSwDevice` [in]

The handle for the software device.

### `CreateResult` [in]

An HRESULT that indicates if the enumeration of the software device was successful.

### `pContext` [in, optional]

The context that was optionally supplied by the client app to [SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate).

### `pszDeviceInstanceId` [in, optional]

The device instance ID that PnP assigned to the device.

## Remarks

The operating system calls the **SW_DEVICE_CREATE_CALLBACK** callback function after PnP enumerates the device. After the callback function is called, the device has backing in the registry and calls to Software Device API functions can be made by using the *hSwDevice* handle. You can also use other APIs that work with devices for the device that is created.

PnP enumeration of a device is the first step that a device undergoes. After PnP enumeration of the device, the device only has registry backing, and you can set properties against the device. Just because PnP enumerated the device, the device hasn't started yet, and no driver for the device has registered or enabled interfaces yet. In many cases, we recommend that apps wait for device-interface arrival if they want to use the device.

**Note** The callback function supplies the device instance ID for the created device. We recommend that callers of the Software Device API not try to guess at or construct the device instance ID themselves; always use the value provided by the callback function.

The callback function will execute on an arbitrary thread-pool thread. Client apps can perform as much work as needed in the callback function.

In Windows 8, you can't call [SwDeviceClose](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdeviceclose) inside the callback function. Doing so will cause a deadlock. Be careful of releasing a ref counted object that will call **SwDeviceClose** when its destructor runs. In Windows 8.1, this restriction is lifted, and you can call **SwDeviceClose** inside the callback function.

Always check the HRESULT that is passed to *CreateResult* to make sure PnP was able to enumerate the device.

## See also

[SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate)