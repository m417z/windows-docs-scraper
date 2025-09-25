# SwDeviceGetLifetime function

## Description

Gets the lifetime of a software device.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to the software device to retrieve.

### `pLifetime` [in]

A pointer to a variable that receives a **SW_DEVICE_LIFETIME**-typed value that indicates the current lifetime value for the software device. Here are possible values:

| Value | Meaning |
| --- | --- |
| **SWDeviceLifetimeHandle** | Indicates that the lifetime of the software device is determined by the lifetime of the handle that is associated with the software device. As long as the handle is open, the software device is enumerated by PnP. |
| **SWDeviceLifetimeParentPresent** | Indicates that the lifetime of the software device is tied to the lifetime of its parent. |

## Return value

S_OK is returned if [SwDeviceSetLifetime](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicesetlifetime) successfully retrieved the lifetime.