# PUSB_BUSIFFN_QUERY_CONTROLLER_TYPE callback function

## Description

The **QueryControllerType** routine gets information about the USB host controller to which the USB device is attached.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_QUERY_CONTROLLER_TYPE) (
    IN PVOID,
    OUT PULONG,
    OUT PUSHORT,
    OUT PUSHORT,
    OUT PUCHAR,
    OUT PUCHAR,
    OUT PUCHAR,
    OUT PUCHAR
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v3) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [out]

Reserved. Do not use.

### `unnamedParam3` [out]

Pointer to a UCHAR variable that receives the PCI class for the USB host controller.

### `unnamedParam4` [out]

Pointer to a USHORT variable that receives the PCI device ID for the USB host controller.

### `unnamedParam5` [out]

Pointer to a UCHAR variable that receives the PCI programming interface for the USB host controller.

### `unnamedParam6` [out]

Pointer to a UCHAR variable that receives the PCI revision number for the USB host controller.

### `unnamedParam7` [out]

Pointer to a UCHAR variable that receives the PCI subclass for the USB host controller.

### `unnamedParam8` [out]

Pointer to a USHORT variable that receives the PCI vendor ID for the USB host controller.

## Return value

Returns STATUS_SUCCESS on success, and the appropriate error code on failure.

## Remarks

*PciClass* is typically set to PCI_CLASS_SERIAL_BUS_CTLR (0x0C).

*PciSubClass* is typically set to PCI_SUBCLASS_SB_USB (0x03).

*PciProgif* is typically set to one of the following values:

- 0x00 - Universal Host Controller Interface (UHCI)
- 0x10 - Open Host Controller Interface (OHCI)
- 0x20 - Enhanced Host Controller Interface (EHCI)

## See also

- [USB_BUS_INTERFACE_USBDI_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v3)