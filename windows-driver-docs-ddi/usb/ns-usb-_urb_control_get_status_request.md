# _URB_CONTROL_GET_STATUS_REQUEST structure

## Description

The _URB_CONTROL_GET_STATUS_REQUEST structure is used by USB client drivers to retrieve status from a device, interface, endpoint, or other device-defined target.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Length** must be `sizeof(_URB_CONTROL_GET_STATUS_REQUEST)`, and **Hdr.Function** must be one of the following values:

* URB_FUNCTION_GET_STATUS_FROM_DEVICE
* URB_FUNCTION_GET_STATUS_FROM_INTERFACE
* URB_FUNCTION_GET_STATUS_FROM_ENDPOINT
* URB_FUNCTION_GET_STATUS_FROM_OTHER

### `Reserved`

Reserved. Do not use.

### `Reserved0`

Reserved. Do not use.

### `TransferBufferLength`

Must be 2. This member specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**. The host controller driver returns the number of bytes sent to or read from the pipe in this member.

### `TransferBuffer`

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in **TransferBufferMDL**. The bus driver returns a single byte specifying the status for the target.

### `TransferBufferMDL`

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in **TransferBuffer**. The bus driver returns a single byte specifying the status for the target. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

### `Reserved1`

Reserved. Do not use.

### `Index`

Specifies the device-defined index, returned by a successful configuration request, if the request is for an endpoint or interface. Otherwise, **Index** must be zero.

### `Reserved2`

Reserved. Do not use.

## Remarks

Drivers can use the [UsbBuildGetStatusRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbbuildgetstatusrequest) service routine to format this URB.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)