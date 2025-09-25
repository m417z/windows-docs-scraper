# _BRB_ACL_GET_MODE structure

## Description

The _BRB_ACL_GET_MODE structure describes the ACL mode for the specified remote device.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote device.

### `AclMode`

A value from the
[ACL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_acl_mode) enumeration that specifies the ACL mode of
the remote device.

## Remarks

To get the current ACL connection state for a remote device, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_ACL_GET_MODE](https://learn.microsoft.com/previous-versions/ff536609(v=vs.85)) request.

## See also

[ACL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_acl_mode)

[BRB_ACL_GET_MODE](https://learn.microsoft.com/previous-versions/ff536609(v=vs.85))

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)