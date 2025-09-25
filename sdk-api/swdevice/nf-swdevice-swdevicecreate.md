# SwDeviceCreate function

## Description

Initiates the enumeration of a software device.

## Parameters

### `pszEnumeratorName` [in]

A string that names the enumerator of the software device. Choose a name that represents the component that enumerates the devices.

### `pszParentDeviceInstance` [in]

A string that specifies the device instance ID of the device that is the parent of the software device.

This can be HTREE\ROOT\0, but we recommend to keep children of the root device to a minimum. We also recommend that the preferred parent of a software device be a real device that the software device is extending the functionality for. In situations where a software device doesn't have such a natural parent, create a device as a child of the root that can collect all the software devices that a component will enumerate; then, enumerate the actual software devices as children of this device grouping node. This keeps the children of the root device to a manageable number.

### `pCreateInfo` [in]

A pointer to a [SW_DEVICE_CREATE_INFO](https://learn.microsoft.com/windows/desktop/api/swdevicedef/ns-swdevicedef-sw_device_create_info) structure that describes info that PnP uses to create the device.

### `cPropertyCount` [in]

The number of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures in the *pProperties* array.

### `pProperties` [in, optional]

An optional array of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures. These properties are set on the device after it is created but before a notification that the device has been created are sent. For more info, see Remarks. This pointer can be **NULL**.

### `pCallback` [in]

The [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function that the operating system calls after PnP enumerates the device.

### `pContext` [in, optional]

An optional client context that the operating system passes to the callback function. This pointer can be **NULL**.

### `phSwDevice` [out]

A pointer to a variable that receives the **HSWDEVICE** handle that represents the device. Call [SwDeviceClose](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdeviceclose) to close this handle after the client app wants PnP to remove the device.

``` syntax

DECLARE_HANDLE(HSWDEVICE);
typedef HSWDEVICE *PHSWDEVICE;

```

## Return value

S_OK is returned if device enumeration was successfully initiated. This does not mean that the device has been successfully enumerated. Check the *CreateResult* parameter of the [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function to determine if the device was successfully enumerated.

## Remarks

**SwDeviceCreate** returns a handle that represents the device. After this handle is closed, PnP will remove the device.

The calling process must have Administrator access in order to initiate the enumeration of a software device.

PnP forms the device instance ID of a software device as "SWD\<pszEnumeratorName>\<pszInstanceId>," but this string might change or PnP might decorate the name. Always get the device instance ID from the callback function.

There is a subtle difference between properties that are set as part of a **SwDeviceCreate** call and properties that are later set by calling [SwDevicePropertySet](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicepropertyset). Properties that are set as part of **SwDeviceCreate** are stored in memory; if the device is uninstalled or a null driver wipes out the property stores, these properties are written out again by the Software Device API feature when PnP re-enumerates the devices. This is all transparent to the client. Properties that are set using **SwDevicePropertySet** after the enumeration don't persist in memory. But, if you set a property by using **SwDeviceCreate**, you can update the value with **SwDevicePropertySet**, and this update is applied to the in-memory value as well as the persisted store.

We recommend that all properties be specified as part of the call to **SwDeviceCreate** when possible and that these properties be specified for every call to **SwDeviceCreate**.

**Note** The operating system might possibly call [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) before the call to **SwDeviceCreate** returns. For this reason, the software device handle for the device is supplied as a parameter to the callback function.

You can create a software device as the child of a parent that is not present at the time. PnP will enumerate the software device after the parent becomes present.

## See also

[SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback)