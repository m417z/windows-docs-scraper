# PUSB_BUSIFFN_QUERY_BUS_TIME callback function

## Description

The *QueryBusTime* function gets the current 32-bit USB frame number.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_TIME) (
    IN PVOID,
    IN PULONG
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [out, optional]

Receives the current USB frame number.

## Return value

Returns STATUS_SUCCESS on success, and the appropriate error code on failure.

## Remarks

This routine replaces the **USBD_QueryBusTime** library function provided by *usbd.sys*.

## See also

- [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0)