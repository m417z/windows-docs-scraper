# PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB callback function

## Description

This callback function is not supported.

The *SubmitIsoOutUrb* function submits a USB request block (URB) directly to the bus driver without requiring the allocation of an IRP.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB) (
    IN PVOID,
    IN PURB
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the *BusContext* member of the [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [in]

Pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to be passed to the port driver.

## Return value

**SubmitIsoOutUrb** returns one of the following values:

| Return code | Description |
|------------------------|---------------------------------------------------------------------------------------------|
| `STATUS_SUCCESS` | The call completed successfully. |
| `STATUS_NOT_SUPPORTED` | Fast isochronous interfaces and real-time threads are not supported by the host controller. |

## Remarks

This function replaces the **USBD_BusSubmitIsoOutUrb** library function provided by *usbd.sys*.

This function allows clients running in real-time threads at an elevated IRQL to have rapid access to the bus driver. This USB host controller must support real-time threads for this function to work.

The calling driver forfeits any packet-level error information when calling this function.

## -seealso

- [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0)
- [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)