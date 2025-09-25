# _WWAN_ACTIVATION_STATE enumeration

## Description

The WWAN_ACTIVATION_STATE enumeration lists the different Packet Data Protocol (PDP) context
activation states that are supported by the MB device.

## Constants

### `WwanActivationStateUnknown`

The activation state is unknown.

### `WwanActivationStateActivated`

The packet context is activated.

### `WwanActivationStateActivating`

The packet context is currently in the process of getting activated.

### `WwanActivationStateDeactivated`

The packet context is not activated.

### `WwanActivationStateDeactivating`

The packet context is currently in the process of getting deactivated.

### `WwanActivationStateMax`

The total number of PDP activation states.

## Remarks

Miniport drivers use the
**WwanActivationStateActivating** and
**WwanActivationStateDeactivating** transient states when responding to
*query* requests. Miniport driver should not return these states when processing
*set* requests. Miniport drivers must only send
*set* indications after they have successfully activated or deactivated a PDP context, and not
immediately after receiving the request.

## See also

[WWAN_SET_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_state)