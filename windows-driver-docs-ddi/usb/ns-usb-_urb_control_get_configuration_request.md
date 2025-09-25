# _URB_CONTROL_GET_CONFIGURATION_REQUEST structure

## Description

The _URB_CONTROL_GET_CONFIGURATION_REQUEST structure is used by USB client drivers to retrieve the current configuration for a device.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be set to URB_FUNCTION_GET_CONFIGURATION.

**Hdr.Length** must equal `sizeof(_URB_CONTROL_GET_CONFIGURATION_REQUEST)`.

### `Reserved`

Reserved. Do not use.

### `Reserved0`

Reserved. Do not use.

### `TransferBufferLength`

Must be 1. This member specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**.

### `TransferBuffer`

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in **TransferBufferMDL**. The bus driver returns a single byte that specifies the index of the current configuration.

### `TransferBufferMDL`

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in **TransferBuffer**. The bus driver returns a single byte that specifies the index of the current configuration. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

### `Reserved1`

Reserved. Do not use.

## Remarks

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)