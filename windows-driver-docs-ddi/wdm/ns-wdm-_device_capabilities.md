## Description

A **DEVICE_CAPABILITIES** structure describes PnP and power capabilities of a device. This structure is returned in response to an [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) IRP.

## Members

### `Size`

Specifies the size of the structure, in bytes. This field is set by the component that sends the **IRP_MN_QUERY_CAPABILITIES** request.

### `Version`

Specifies the version of the structure, currently version 1. This field is set by the component that sends the **IRP_MN_QUERY_CAPABILITIES** request.

### `DeviceD1`

Specifies whether the device hardware supports the D1 power state. Drivers should not change this value.

### `DeviceD2`

Specifies whether the device hardware supports the D2 power state. Drivers should not change this value.

### `LockSupported`

Specifies whether the device supports physical-device locking that prevents device ejection. This member pertains to ejecting the device from its slot, rather than ejecting a piece of removable media from the device.

### `EjectSupported`

Specifies whether the device supports software-controlled device ejection while the system is in the **PowerSystemWorking** state. This member pertains to ejecting the device from its slot, rather than ejecting a piece of removable media from the device.

### `Removable`

Specifies whether the device can be dynamically removed from its immediate parent. If **Removable** is set to **TRUE**, the device does not belong to the same physical object as its parent.

For example, if **Removable** is set to **TRUE** for a USB composite device inside a multifunction printer, the composite device does not belong to the physical object of its immediate parent, such as a USB hub inside a notebook PC.

In most cases the bus driver, not the function driver, should determine the value of the **Removable** parameter of the device. For USB devices, the USB hub driver sets the **Removable** parameter. It should not be modified by the function driver.

If **Removable** is set to **TRUE**, the device is displayed in the **Unplug or Eject Hardware** program, unless **SurpriseRemovalOK** is also set to **TRUE**.

### `DockDevice`

Specifies whether the device is a docking peripheral.

### `UniqueID`

Specifies whether the device's instance ID is unique system-wide. This bit is clear if the instance ID is unique only within the scope of the bus. For more information, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `SilentInstall`

Specifies whether Device Manager should suppress all installation dialog boxes; except required dialog boxes such as "no compatible drivers found."

### `RawDeviceOK`

Specifies whether the driver for the underlying bus can drive the device if there is no function driver (for example, SCSI devices in pass-through mode). This mode of operation is called [raw mode](https://learn.microsoft.com/windows-hardware/drivers/).

### `SurpriseRemovalOK`

Specifies whether the function driver for the device can handle the case where the device is removed before Windows can send **IRP_MN_QUERY_REMOVE_DEVICE** to it. If **SurpriseRemovalOK** is set to **TRUE**, the device can be safely removed from its immediate parent regardless of the state that its driver is in.

For example, a standard USB mouse does not maintain any state in its hardware and thus can be safely removed at any time. However, an external hard disk whose driver caches writes in memory cannot be safely removed without first letting the driver flush its cache to the hardware.

Drivers for USB devices that support surprise removal must set this to **TRUE** only when the IRP is being passed back up the driver stack.

### `WakeFromD0`

Specifies whether the device can respond to an external wake signal while in the D0 state. Drivers should not change this value.

### `WakeFromD1`

Specifies whether the device can respond to an external wake signal while in the D1 state. Drivers should not change this value.

### `WakeFromD2`

Specifies whether the device can respond to an external wake signal while in the D2 state. Drivers should not change this value.

### `WakeFromD3`

Specifies whether the device can respond to an external wake signal while in the D3 state. Drivers should not change this value.

### `HardwareDisabled`

When set, this flag specifies that the device's hardware is disabled.

A device's parent bus driver or a bus filter driver sets this flag when such a driver determines that the device hardware is disabled.

The PnP manager sends one **IRP_MN_QUERY_CAPABILITIES** IRP right after a device is enumerated and sends another after the device has been started. The PnP manager only checks this bit right after the device is enumerated. Once the device is started, this bit is ignored.

### `NonDynamic`

Reserved for future use.

### `WarmEjectSupported`

Reserved for future use.

### `NoDisplayInUI`

Do not display the device in the user interface. If this bit is set, the device is never displayed in the user interface, even if the device is present but fails to start. Only bus drivers and associated bus filter drivers should set this bit. (Also see the **PNP_DEVICE_DONT_DISPLAY_IN_UI** flag in the [PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-surprise-removal-request#about-pnp_device_state) structure.)

### `Reserved1`

Reserved for system use.

### `WakeFromInterrupt`

Indicates whether the driver or ACPI is responsible for handling the wake event. If set, the driver is responsible for handling the wake event. ACPI arms the device when it receives an IRP_MN_WAIT_WAKE IRP, but does not connect the interrupt, complete the IRP to notify the device stack of a wake event.

### `SecureDevice`

Indicates whether the device is a secure device.

### `ChildOfVgaEnabledBridge`

For a VGA device, indicates whether the parent bridge has the VGA decoding bit set.

### `DecodeIoOnBoot`

Indicates whether the device has IO decode enabled on boot.

### `Reserved`

Reserved for system use.

### `Address`

Specifies an address indicating where the device is located on its underlying bus.

The interpretation of this number is bus-specific. If the address is unknown or the bus driver does not support an address, the bus driver leaves this member at its default value of 0xFFFFFFFF.

The following list describes the information certain bus drivers store in the **Address** field for their child devices:

| Bus | Description |
|---|---|
| 1394 | Does not supply an address because the addresses are volatile. Defaults to 0xFFFFFFFF. |
| EISA | Slot Number (0-F). |
| IDE | For an IDE device, the address contains the target ID and LUN. For an IDE channel, the address is zero or one (0 = primary channel and 1 = secondary channel). |
| ISApnp | Does not supply an address. Defaults to 0xFFFFFFFF. |
| PC Card (PCMCIA) | The socket number (typically 0x00 or 0x40). |
| PCI | The device number in the high word and the function number in the low word. |
| SCSI | The target ID. |
| USB | The port number. |

### `UINumber`

Specifies a number associated with the device that can be displayed in the user interface.

This number is typically a user-perceived slot number, such as a number printed next to the slot on the board, or some other number that makes locating the physical device easier for the user. For buses with no such convention, or when the **UINumber** is unknown, the bus driver leaves this member at its default value of 0xFFFFFFFF.

### `DeviceState`

An array of values indicating the most-powered device power state that the device can maintain for each system power state. The **DeviceState[PowerSystemWorking]** element of the array corresponds to the S0 system state. The entry for **PowerSystemUnspecified** is reserved for system use.

The entries in this array are based on the capabilities of the parent devnode. As a general rule, a driver should not change these values. However, if necessary, a driver can lower the value, for example, from **PowerDeviceD1** to **PowerDeviceD2**.

If the bus driver is unable to determine the appropriate device power state for a root-enumerated device, it sets **DeviceState[PowerSystemWorking]** to **PowerDeviceD0** and all other entries to **PowerDeviceD3**.

### `SystemWake`

Specifies the least-powered system power state from which the device can signal a wake event. A value of **PowerSystemUnspecified** indicates that the device cannot wake the system.

A bus driver can get this information from its parent devnode.

In general, a driver should not change this value. If necessary, however, a driver can raise the power state, for example, from **PowerSystemHibernate** to **PowerSystemS1**, to indicate that its device cannot wake the system from a hibernation state but can from a higher-powered sleep state.

### `DeviceWake`

Specifies the least-powered device power state from which the device can signal a wake event. A value of **PowerDeviceUnspecified** indicates that the device cannot signal a wake event.

### `D1Latency`

Specifies the device's approximate worst-case latency, in 100-microsecond units, for returning the device to the **PowerDeviceD0** state from the **PowerDeviceD1** state. Set to zero if the device does not support the D1 state.

### `D2Latency`

Specifies the device's approximate worst-case latency, in 100-microsecond units, for returning the device to the **PowerDeviceD0** state from the **PowerDeviceD2** state. Set to zero if the device does not support the D2 state.

### `D3Latency`

Specifies the device's approximate worst-case latency, in 100-microsecond units, for returning the device to the **PowerDeviceD0** state from the **PowerDeviceD3** state. Set to zero if the device does not support the D3 state.

## Remarks

Bus drivers set the appropriate values in this structure in response to an **IRP_MN_QUERY_CAPABILITIES** IRP. Bus filter drivers, function drivers, and filter drivers might alter the capabilities set by the bus driver.

Drivers that send an **IRP_MN_QUERY_CAPABILITIES** request must initialize the **Size**, **Version**, **Address**, and **UINumber** members of this structure before sending the IRP.

For more information about using the **DEVICE_CAPABILITIES** structure to describe a device's power capabilities, see [Reporting Device Power Capabilities](https://learn.microsoft.com/windows-hardware/drivers/kernel/reporting-device-power-capabilities).

## See also

[IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities)

[PNP_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-an-irp-mn-surprise-removal-request#about-pnp_device_state)