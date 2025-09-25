# _WDF_DEVICE_STATE structure

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_STATE** structure specifies a device's Plug and Play state.

## Members

### `Size`

The size, in bytes, of this structure.

### `Disabled`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device is disabled. For more information about the **WDF_TRI_STATE** type, see the following Remarks section.

### `DontDisplayInUI`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device is hidden (not displayed) in Device Manager. For more information, see [Viewing Hidden Devices](https://learn.microsoft.com/windows-hardware/drivers/install/viewing-hidden-devices). (After you set this member to **WdfTrue**, changing its value has no effect.)

### `Failed`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device is present but has failed.

### `NotDisableable`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device cannot be disabled.

### `Removed`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device has been removed.

### `ResourcesChanged`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device's resource requirements have changed.

### `AssignedToGuest`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the device is reporting itself as assigned to a guest partition.

## Remarks

Structure members use the [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state) type. A value of **WdfUseDefault** indicates the framework will use the value that was provided by a lower driver in the stack. For example, if a bus driver specifies **WdfTrue** for **NotDisableable** and the device's function driver specifies **WdfUseDefault**, the framework uses **WdfTrue** for the device state.

The **WDF_DEVICE_STATE** structure is used as a parameter to [WdfDeviceSetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdevicestate) and [WdfDeviceGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicestate).

To initialize a **WDF_DEVICE_STATE** structure, the driver must call [WDF_DEVICE_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_state_init).

For more information about the members of the **WDF_DEVICE_STATE** structure, see [PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-surprise-removal-request#about-pnp_device_state).