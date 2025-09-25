# _WWAN_CONTEXT_OPERATIONS enumeration

## Description

The **WWAN_CONTEXT_OPERATIONS** enumeration specifies the types of operation used in a Set request for a provisioned context in a mobile broadband (MBB) modem.

## Constants

### `WwanContextOperationDefault`

The default operation for overwriting an existing context in the modem.

### `WwanContextOperationDelete`

Delete the context.

### `WwanContextOperationRestoreFactory`

Restore factory preconfigured contexts for the Provider ID of the currently inserted SIM.

### `WwanContextOperationMaximum`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2) structure.

## See also

[**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2)