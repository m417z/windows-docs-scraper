# PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED callback function

## Description

The USB_BUSIFFN_IS_DEVICE_HIGH_SPEED routine returns `TRUE` if the device is operating at high speed.

## Syntax

```cpp
typedef BOOLEAN
  (USB_BUSIFFN *PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED) (
    IN PVOID
  );
```

## Parameters

### `unnamedParam1` [in, optional]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v1) structure by an IRP_MN_QUERY_INTERFACE request.

## Return value

USB_BUSIFFN_IS_DEVICE_HIGH_SPEED implementation returns `TRUE` if the USB device is operating at high speed USB 2.0 compliant device; `FALSE` otherwise.

## Remarks

## See also

- [USB_BUS_INTERFACE_USBDI_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v1)