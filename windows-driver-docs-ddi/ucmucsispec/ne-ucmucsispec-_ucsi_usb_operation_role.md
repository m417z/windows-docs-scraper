# _UCSI_USB_OPERATION_ROLE enumeration

## Description

Used in the SET_UOR command. The SET_UOR command is used to set the USB operation role dictated by the OS Policy Manager (OPM), for the current connection.

## Constants

### `UcsiUsbOperationRoleDfp:0x1`

The connector initiates swap to downstream-facing port (DFP), if not already operating in DFP mode.

### `UcsiUsbOperationRoleUfp:0x2`

The connector initiates swap to upstream-facing port (UFP), if not already operating in UFP mode.

### `UcsiUsbOperationRoleAcceptSwap:0x4`

The connector accepts USB operation role swap requests from the port partner. If this bit is cleared, connector rejects role swap requests from the port partner.

### `UcsiUsbOperationRoleDfpAcceptSwap:0x5`

This field combines the *UcsiUsbOperationRoleDfp* and *UcsiUsbOperationRoleAcceptSwap* values.

### `UcsiUsbOperationRoleUfpAcceptSwap:0x6`

This field combines the *UcsiUsbOperationRoleUfp* and *UcsiUsbOperationRoleAcceptSwap* values.

## Remarks

For more information, see section 4.5.9 in the [UCSI spec version 1.2](https://www.intel.com/content/www/us/en/products/docs/io/universal-serial-bus/usb-type-c-ucsi-spec.html).

## See also

- [UCSI spec version 1.2](https://www.intel.com/content/www/us/en/products/docs/io/universal-serial-bus/usb-type-c-ucsi-spec.html)