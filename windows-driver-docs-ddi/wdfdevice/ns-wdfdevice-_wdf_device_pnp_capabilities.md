# _WDF_DEVICE_PNP_CAPABILITIES structure

## Description

[Applies to KMDF and UMDF]

The WDF_DEVICE_PNP_CAPABILITIES structure describes a device's Plug and Play capabilities.

## Members

### `Size`

The size, in bytes, of this structure.

### `LockSupported`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device can be locked in its slot to prevent ejection. (This capability disables ejecting a device from its slot, not ejecting media from a device.) For more information about WDF_TRI_STATE-typed values, see the following Remarks section.

### `EjectSupported`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that the device can be ejected from its slot. (This capability enables ejecting a device from its slot, not ejecting media from a device.)

### `Removable`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that the device can be removed while the system is running. If **Removable** is set to **WdfTrue** and **SurpriseRemovalOK** is set to **WdfFalse**, users should use the system's Unplug or Eject Hardware program.

### `DockDevice`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that the device is a docking station.

### `UniqueID`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that the device's instance ID is unique to the entire system. If **UniqueID** is set to **WdfFalse**, the instance ID is unique only to the device's bus. For more information about instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `SilentInstall`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that Device Manager should not display dialog boxes during installation of the device.

### `SurpriseRemovalOK`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue** (and if **Removable** is also set to **WdfTrue**), that users can remove the device without using the system's Unplug or Eject Hardware program.

### `HardwareDisabled`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that the device is disabled.

### `NoDisplayInUI`

A WDF_TRI_STATE-typed value that indicates, if set to **WdfTrue**, that Device Manager should not display the device.

### `Address`

An address that indicates where the device is located on its bus.

The interpretation of this number is bus-specific. If the address is unknown or the bus driver does not support an address, the bus driver leaves the **Address** member at its default value of 0xFFFFFFFF (-1).

The following list describes the information that certain bus drivers store in the **Address** member for their child devices:

| Bus | Description |
|-----|-------------|
| 1394 | Does not supply an address because the addresses are volatile. Defaults to 0xFFFFFFFF. |
| EISA | Slot Number (0-F). |
| IDE | For an IDE device, the address contains the target ID and LUN. For an IDE channel, the address is zero or one (0 = primary channel and 1 = secondary channel). |
| ISApnp | Does not supply an address. Defaults to 0xFFFFFFFF. |
| PC Card (PCMCIA) | The socket number (typically 0x00 or 0x40). |
| PCI | The device number in the high word and the function number in the low word. |
| SCSI | The target ID. |
| USB | The port number. |

### `UINumber`

A number that is associated with the device and can be displayed in user interfaces. This number is typically a user-perceived slot number, such as a number printed next to the slot on the board or some other number that helps the user locate the device. If **UINumber** is unknown, or if supplying a number would not assist the user in identifying the device's location, the driver sets this value to -1.

## Remarks

Several members use the [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state) type. For these members, a value of **WdfTrue** indicates that the device supports the capability and a value of **WdfFalse** indicates it does not. A value of **WdfUseDefault** indicates the framework will use the value that a driver lower in the stack provided. For example, if a bus driver specifies **WdfTrue** for **LockSupported** and the device's function driver specifies **WdfUseDefault**, the framework stores **WdfTrue** for the capability.

The WDF_DEVICE_PNP_CAPABILITIES structure is used as input to [WdfDeviceSetPnpCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpnpcapabilities).

To initialize a WDF_DEVICE_PNP_CAPABILITIES structure, a driver should call [WDF_DEVICE_PNP_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_pnp_capabilities_init).

## See also

[WdfDeviceSetPowerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpowercapabilities)

[WdfPdoInitAssignRawDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassignrawdevice)