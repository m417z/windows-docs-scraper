# _ACL_MODE enumeration

## Description

The ACL_MODE enumeration type is used to list the possible states of an ACL connection.

## Constants

### `ACL_MODE_ACTIVE`

This value indicates the ACL is in an active state.

### `ACL_MODE_HOLD`

This value indicates the ACL is in a hold state.

### `ACL_MODE_SNIFF`

This value indicates the ACL is in a sniffed state.

### `ACL_MODE_PARK`

This value indicates the ACL is in a parked state.

### `ACL_MODE_ENTER_ACTIVE`

This value indicates the ACL is entering an active state.

### `ACL_MODE_ENTER_HOLD`

This value indicates the ACL is entering a hold state.

### `ACL_MODE_ENTER_SNIFF`

This value indicates the ACL is entering a sniffed state.

### `ACL_MODE_ENTER_PARK`

This value indicates the ACL is entering a parked state.

### `ACL_DISCONNECTED`

This value indicates the ACL is disconnected.

## Remarks

The
[_BRB_ACL_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_get_mode) structure uses this
enumeration.

## See also

[_BRB_ACL_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_get_mode)