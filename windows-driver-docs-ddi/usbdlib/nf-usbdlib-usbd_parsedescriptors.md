# USBD_ParseDescriptors function

## Description

 The **USBD_ParseDescriptors** routine searches a given configuration descriptor and returns a pointer to the first descriptor that matches the search criteria.

## Parameters

### `DescriptorBuffer` [in]

Pointer to a configuration descriptor that contains the descriptor for which to search.

### `TotalLength` [in]

Specifies the size, in bytes, of the buffer pointed to by *DescriptorBuffer*.

### `StartPosition` [in]

Pointer to the address within the configuration descriptor, provided at *DescriptorBuffer*, to begin searching from. To search from the beginning of the configuration descriptor, the parameters *DescriptorBuffer* and *StartPosition* must be the same address.

### `DescriptorType` [in]

Specifies the descriptor type code as assigned by USB. The following values are valid for USB-defined descriptor types:

#### USB_STRING_DESCRIPTOR_TYPE

Specifies that the descriptor being searched for is a string descriptor.

#### USB_INTERFACE_DESCRIPTOR_TYPE

Specifies that the descriptor being searched for is an interface descriptor.

#### USB_ENDPOINT_DESCRIPTOR_TYPE

Specifies that the descriptor being searched for is an endpoint descriptor.

## Return value

**USBD_ParseDescriptors** returns a pointer to a [USB_COMMON_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_common_descriptor) structure that is the head of the first descriptor that matches the given search criteria, or **NULL** is returned if no match is found:

## Remarks

This structure is used to hold a portion of a descriptor, so that the caller of **USBD_ParseDescriptors** can determine the correct structure to use to access the remaining data in the descriptor. Every descriptor type has these fields at the beginning of the data and callers can use the **bLength** and **bDescriptorType** members to correctly identify the type of this descriptor.

When this routine parses the configuration descriptor looking for the descriptor that matches the search criteria, it returns the first match, terminating the search.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)