# _USB_ID_STRING structure

## Description

The **USB_ID_STRING** structure is used to store a string or multi-string.

## Members

### `LanguageId`

Indicates that language ID of the string.

### `Pad`

### `LengthInBytes`

Indicates the length (in bytes) of the string pointed to by **Buffer**, including the terminating **NULL**.

### `Buffer`

Pointer to a string or multi-string.

## Remarks

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)