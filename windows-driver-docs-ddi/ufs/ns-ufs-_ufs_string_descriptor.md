# _UFS_STRING_DESCRIPTOR structure

## Description

The **UFS_STRING_DESCRIPTOR** structure describes either the Manufacturer Name, Product Name, OEM ID, or Serial Number as a string.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the type of the descriptor. This descriptor will have a value of **UFS_DESC_STRING_IDN**.

### `String`

Contains either the Manufacturer Name, Product Name, OEM ID, or Serial Number as a string.