# _USB_COMMON_DESCRIPTOR structure

## Description

The **USB_COMMON_DESCRIPTOR** structure contains the head of the first descriptor that matches the search criteria in a call to [USBD_ParseDescriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parsedescriptors).

## Members

### `bLength`

Specifies the entire length of the descriptor, not of this structure.

### `bDescriptorType`

Specifies the descriptor type code, as assigned by USB, for this descriptor.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_ParseDescriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parsedescriptors)