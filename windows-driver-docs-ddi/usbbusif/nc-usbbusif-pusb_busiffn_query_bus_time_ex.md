# PUSB_BUSIFFN_QUERY_BUS_TIME_EX callback function

## Description

This request is not supported.

The **QueryBusTimeEx** routine gets the current 32-bit USB micro-frame number.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_TIME_EX) (
    IN PVOID,
    IN PULONG
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v3) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [out]

Receives the current USB micro-frame number.

## Return value

**QueryBusTimeEx** returns one of the following values:

| Return code | Description |
|------------------------|----------------------------------------------------------------------------------|
| `STATUS_SUCCESS` | The call completed successfully. |
| `STATUS_NOT_SUPPORTED` | The function was called for a USB host controller that does not support USB 2.0. |

## Remarks

**QueryBusTimeEx** gets the current USB 2.0 frame/micro-frame number when called for a USB device attached to a USB 2.0 host controller.

The lowest 3 bits of the returned micro-frame value will contain the current 125us micro-frame, while the upper 29 bits will contain the current 1ms USB frame number.

## See also

- [USB_BUS_INTERFACE_USBDI_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v3)