# TC_IFC_DESCRIPTOR structure

## Description

The
**TC_IFC_DESCRIPTOR** structure is an interface identifier used to enumerate interfaces.

## Members

### `Length`

Number of bytes from the beginning of the
**TC_IFC_DESCRIPTOR** to the next
**TC_IFC_DESCRIPTOR**.

### `pInterfaceName`

Pointer to a zero-terminated Unicode string representing the name of the packet shaper interface. This name is used in subsequent TC API calls to reference the interface.

### `pInterfaceID`

Pointer to a zero-terminated Unicode string naming the DeviceName of the interface.

### `AddressListDesc`

Network address list descriptor.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)