# SwDeviceInterfacePropertySet function

## Description

Sets properties on a software device interface.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to the software device of the interface to set properties for.

### `pszDeviceInterfaceId` [in]

A string that identifies the interface to set properties on.

### `cPropertyCount` [in]

The number of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures in the *pProperties* array.

### `pProperties` [in]

An array of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures containing the properties to set on the interface.

## Return value

S_OK is returned if **SwDeviceInterfacePropertySet** successfully set the properties on the interface; otherwise, an appropriate error value.

## Remarks

You can call **SwDeviceInterfacePropertySet** only after the operating system has called your client app's [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function to notify the client app that device enumeration completed.

There is a subtle difference between properties that are set as part of a [SwDeviceInterfaceRegister](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdeviceinterfaceregister) call and properties that are later set by calling **SwDeviceInterfacePropertySet**. Properties that are set as part of **SwDeviceInterfaceRegister** are stored in memory; if the device is uninstalled or a null driver wipes out the property stores, these properties are written out again by the Software Device API feature when PnP re-enumerates the devices. This is all transparent to the client. Properties that are set using **SwDeviceInterfacePropertySet** after the enumeration don't persist in memory. But, if you set a property by using **SwDeviceInterfaceRegister**, you can update the value with **SwDeviceInterfacePropertySet**, and this update is applied to the in-memory value as well as the persisted store.

You can use **SwDeviceInterfacePropertySet** only to set properties in the operating system store for the interface.