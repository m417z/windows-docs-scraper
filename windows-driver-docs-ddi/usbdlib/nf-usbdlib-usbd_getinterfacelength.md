# USBD_GetInterfaceLength function

## Description

 The **USBD_GetInterfaceLength** routine obtains the length of a given interface descriptor, including the length of all endpoint descriptors contained within the interface.

## Parameters

### `InterfaceDescriptor` [in]

Pointer to a interface descriptor for which to obtain the length.

### `BufferEnd` [in]

Pointer to the position within a buffer at which to stop searching for the length of the interface and associated endpoints.

## Return value

**USBD_GetInterfaceLength** returns the length, in bytes, of the interface descriptor and all associated endpoint descriptors contained within the interface.

## Remarks

Callers can use this routine to obtain the length of an interface and associated endpoints that are contained within another buffer. For example, a caller could specify a location inside of a larger buffer for *InterfaceDescriptor* and the beginning of a location of another interface descriptor for *BufferEnd*. This will cause the routine to search only from the beginning of the interface descriptor specified by *InterfaceDescriptor* until either it finds another interface descriptor or it reaches the position specified by *BufferEnd*.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)