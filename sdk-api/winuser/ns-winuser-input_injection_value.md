# INPUT_INJECTION_VALUE structure

## Description

Contains the input injection details.

## Members

### `page`

The Usage Page ID, such as VR Controls Page (0x03) or Game Controls Page (0x05).

### `usage`

 The Usage ID associated with a Usage Page, such as Turn Right/Left (21) or Move Right/Left (24) for a Game Controls Page.

### `value`

The injected input value.

### `index`

The Usage index, such as the selected item in a radio button set.

## See also

[Universal Serial Bus HID Usage Tables - USB.org](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)