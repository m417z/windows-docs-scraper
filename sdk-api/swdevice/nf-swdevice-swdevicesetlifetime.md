# SwDeviceSetLifetime function

## Description

Manages the lifetime of a software device.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to the software device to manage.

### `Lifetime` [in]

A **SW_DEVICE_LIFETIME**-typed value that indicates the new lifetime value for the software device. Here are possible values:

| Value | Meaning |
| --- | --- |
| **SWDeviceLifetimeHandle** | Indicates that the lifetime of the software device is determined by the lifetime of the handle that is associated with the software device. As long as the handle is open, the software device is enumerated by PnP. |
| **SWDeviceLifetimeParentPresent** | Indicates that the lifetime of the software device is tied to the lifetime of its parent. |

## Return value

S_OK is returned if **SwDeviceSetLifetime** successfully updated the lifetime.

## Remarks

After a software device is initially created by calling [SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate), its default lifetime is set to **SwDeviceLifetimeHandle**. When a software device has a lifetime of **SwDeviceLifetimeHandle**, PnP stops enumerating the device after the device's handle is closed.

You can use **SwDeviceSetLifetime** to set the lifetime of the software device to **SwDeviceLifetimeParentPresent**. The lifetime of the software device is then tied to the lifetime of the closest non-software device parent. The creator of the software device can then close the handle to the software device and the device will still be enumerated. This can be useful for services that manage software devices but want to idle stop.

A client app can only call **SwDeviceSetLifetime** after it has received a call to its [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function that is associated with its call to [SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate).

When a client app calls [SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate) for a software device that was previously marked for **SwDeviceLifetimeParentPresent**, **SwDeviceCreate** succeeds if there are no open software device handles for the device (only one handle can be open for a device). A client app can then regain control over a persistent software device for the purposes of updating properties and interfaces or changing the lifetime.

If the client app specifies info in [SW_DEVICE_CREATE_INFO](https://learn.microsoft.com/windows/desktop/api/swdevicedef/ns-swdevicedef-sw_device_create_info) that is different form a previous enumeration, the device might stop being enumerated and immediately re-enumerated to apply the changes. The operating system reports only some properties when PnP enumerates the device.

To uninstall a software device with a lifetime of **SwDeviceLifetimeParentPresent**, we recommend that you change the lifetime back to **SwDeviceLifetimeHandle** before the device is uninstalled.