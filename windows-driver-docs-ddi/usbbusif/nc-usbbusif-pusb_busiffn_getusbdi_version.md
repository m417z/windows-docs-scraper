# PUSB_BUSIFFN_GETUSBDI_VERSION callback function

## Description

The **GetUSBDIVersion** routine returns the USB interface version number and the version number of the USB specification that defines the interface, along with information about host controller capabilities.

> [!NOTE]
> [USBD_IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported) replaces the **GetUSBDIVersion** routine. To determine the capabilities of the host controller and the underlying USB driver stack, call [USBD_QueryUsbCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_queryusbcapability).

## Syntax

```cpp
typedef VOID
  (USB_BUSIFFN *PUSB_BUSIFFN_GETUSBDI_VERSION) (
    IN PVOID,
    IN OUT PUSBD_VERSION_INFORMATION,
    IN OUT PULONG
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [out, optional]

Returns the host capability flags. Currently, no host capability flags are reported.

### `unnamedParam3` [out, optional]

Returns a pointer to a [USBD_VERSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_version_information) structure that contains the USB interface version number and the USB specification version number.

## Remarks

The function returns the highest USBDI interface version supported by the port driver. This function replaces the [USBD_GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_getusbdiversion) library function provided by *usbd.sys*.

## See also

- [USBD_GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_getusbdiversion)
- [USBD_VERSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_version_information)
- [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0)