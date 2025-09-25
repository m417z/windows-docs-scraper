# _BRB_ACL_ENTER_ACTIVE_MODE structure

## Description

The _BRB_ACL_ENTER_ACTIVE_MODE structure specifies the remote device to be placed into active
mode.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote device.

## Remarks

To place a remote device into active mode, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_ACL_ENTER_ACTIVE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_enter_active_mode) request.

## See also

[BRB_ACL_ENTER_ACTIVE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_enter_active_mode)

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)