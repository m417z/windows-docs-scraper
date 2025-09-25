# CALLHUB_STATE enumeration

## Description

The
**CALLHUB_STATE** enum is a state indicator returned by the
[ITCallHub::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallhub-get_state) method.

## Constants

### `CHS_ACTIVE:0`

The CallHub is active. There is at least one call that is not in the CS_DISCONNECTED state.

### `CHS_IDLE`

All calls associated with this CallHub are in the CS_DISCONNECTED state.

## See also

[ITCallHub::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallhub-get_state)