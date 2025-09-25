# _WWAN_ACTIVATION_COMMAND enumeration

## Description

The WWAN_ACTIVATION_COMMAND enumeration lists the Packet Data Protocol (PDP) activation commands that
are supported by the MB device.

## Constants

### `WwanActivationCommandDeactivate`

Deactivate a currently activated PDP context identified by
**ConnectionId** .

### `WwanActivationCommandActivate`

Activate PDP context.

### `WwanActivationCommandMax`

The total number of supported activation commands.

### `WwanActivationCommandCancel`

Cancel a currently activated PDP context.

## See also

[WWAN_SET_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_state)