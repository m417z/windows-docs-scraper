# PUSB_BUSIFFN_QUERY_BUS_INFORMATION callback function

## Description

The **QueryBusInformation** routine gets information about the bus.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_INFORMATION) (
    IN PVOID,
    IN ULONG,
    IN OUT PVOID,
    IN OUT PULONG,
    OUT PULONG
  );
```

## Parameters

### `unnamedParam1` [in]

Handle returned in the **BusContext** member of the [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [out, optional]

Specifies the length of the output data.

### `unnamedParam3` [in, out]

Pointer to a buffer that receives the requested bus information.

### `unnamedParam4` [out]

On input, the length of the buffer specified by *BusInformationBuffer*. On output, the length of the output data.

### `unnamedParam5` [in]

Specifies the level of information to be returned. If *Level* is 0, the function returns the total bandwidth and the total consumed bandwidth in bits per second. If *Level* is 1, the function returns the symbolic name of the controller in Unicode, in addition to the total bandwidth and the total consumed bandwidth.

## Return value

**QueryBusInformation** returns one of the following values:

| Return code | Description |
| --- | --- |
| `STATUS_SUCCESS` | The call completed successfully. |
| `STATUS_BUFFER_TOO_SMALL` | The buffer was too small. This error code is returned in two cases:Whenever *Level* == 0, this error code is returned if the size of the buffer pointed to by *BusInformationBuffer* is less than the size of the [USB_BUS_INFORMATION_LEVEL_0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_information_level_0) structure.Whenever Level == 1, this error code is returned if the size of the buffer pointed to by *BusInformationBuffer* less than the size of the [USB_BUS_INFORMATION_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_information_level_1) structure. |

## Remarks

The exact information returned by this routine depends on the value of the *Level* parameter. This routine replaces the **USBD_QueryBusInformation** library function provided by usbd.sys.

## See also

- [USB_BUS_INFORMATION_LEVEL_0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_information_level_0)
- [USB_BUS_INFORMATION_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_information_level_1)
- [USB_BUS_INTERFACE_USBDI_V0](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v0)