# tagKSCAMERA_EXTENDEDPROP_HEADER structure

## Description

The **KSCAMERA_EXTENDEDPROP_HEADER** structure is the payload header for an extended control property.

## Members

### `Version`

The extended property version number. This is set to 1.

### `PinId`

The pin ID that corresponds with the property. If **PinId** is set to (ULONG)-1, the control applies to the filter. Otherwise, the camera driver must route this control to the corresponding pin when that pin is created (or if already available).

### `Size`

The total size, in bytes of the entire payload. This includes the **KSCAMERA_EXTENDEDPROP_HEADER** structure and the following control specific payload data.

### `Result`

For a set operation, this is 0. For queries, **Result** contains any failure code the driver provides for the most recent control operation.

### `Flags`

The settings in **Flags** may vary depending on the control.

The high order bit of the **Flags** value is reserved. This bit serves as the cancel flag and is defined as **KSCAMERA_EXTENDEDPROP_FLAG_CANCELOPERATION**. This flag is only meaningful for asynchronous controls.

### `Capability`

This member is read only and indicates the standard capabilities of the control.

The following capabilities are defined.

| Value | Description |
| --- | --- |
| **KSCAMERA_EXTENDEDPROP_CAPS_ASYNCCONTROL** | The control supports asynchronous operation. |
| **KSCAMERA_EXTENDEDPROP_CAPS_CANCELLABLE** | Applies only to asynchronous controls. This flag marks the control operation as cancellable. If a synchronous control sets this flag, it is be marked as being invalid and is not exposed to higher level applications. |

## See also

[KSCAMERA_EXTENDEDPROP_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_extendedprop_value)