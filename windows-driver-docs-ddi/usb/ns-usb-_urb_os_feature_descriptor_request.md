# _URB_OS_FEATURE_DESCRIPTOR_REQUEST structure

## Description

The **_URB_OS_FEATURE_DESCRIPTOR_REQUEST** structure is used by the USB hub driver to retrieve Microsoft OS Feature Descriptors from a USB device or an interface on a USB device.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR.
**Hdr.Length** must be `sizeof(_URB_OS_FEATURE_DESCRIPTOR_REQUEST)`.

### `Reserved`

### `Reserved0`

### `TransferBufferLength`

Specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**. The host controller driver returns the number of bytes read in this member. Current implementation of this function limits the maximum MS OS Feature Descriptor size to 4 Kilobytes.

### `TransferBuffer`

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in **TransferBufferMDL**.

### `TransferBufferMDL`

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in **TransferBuffer**. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

### `Recipient`

Specifies whether the recipient is the USB device or an interface on the USB device. One of the following values must be specified:

* 0 indicates that the USB device is the recipient of the request.
* 1 indicates that a USB interface is the recipient of the request.
* 2 indicates that a USB endpoint is the recipient of the request.

### `Reserved1`

### `Reserved2`

### `InterfaceNumber`

Indicates the interface number that is the recipient of the request, if the **Recipient** member value is 1. Must be set to 0 if the USB device is the recipient.

### `MS_PageIndex`

Must be set to 0. Page index of the 64K page of the MS OS Feature Descriptor to be returned. Current implementation only supports a maximum descriptor size of 4K.

### `MS_FeatureDescriptorIndex`

Index for MS OS Feature Descriptor to be requested.

### `Reserved3`

## Remarks

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)