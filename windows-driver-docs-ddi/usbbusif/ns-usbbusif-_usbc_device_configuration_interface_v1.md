# _USBC_DEVICE_CONFIGURATION_INTERFACE_V1 structure

## Description

The **USBC_DEVICE_CONFIGURATION_INTERFACE_V1** structure is exposed by the vendor-supplied filter drivers to assist the USB generic parent driver in defining interface collections.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version of the interface.

### `Context`

The USB generic parent driver does not use this member. It is populated by the vendor supplied filter driver and may be used to track instance information for the bus interface. It is passed as a parameter to [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) and [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `InterfaceReference`

Pointer to a routine that increments the number of references to this interface. For more information about this routine, see [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference).

### `InterfaceDereference`

Pointer to a routine that decrements the number of references to this interface. For more information about this routine, see [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `StartDeviceCallback`

Pointer to the callback routine that the filter driver furnishes to the USB generic parent driver to assist in defining interface collections on a device. For more information, see [USBC_START_DEVICE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-usbc_start_device_callback).

### `PdoEnableCallback`

Reserved.

### `Reserved`

Reserved.

## See also

[Customizing Enumeration of Interface Collections for Composite Devices](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBC_START_DEVICE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-usbc_start_device_callback)