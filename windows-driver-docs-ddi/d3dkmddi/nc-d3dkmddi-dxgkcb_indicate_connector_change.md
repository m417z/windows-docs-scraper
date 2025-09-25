# DXGKCB_INDICATE_CONNECTOR_CHANGE callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_INDICATE_CONNECTOR_CHANGE** to indicate that it has added changes to its change queue which the OS should now query.

## Parameters

### `hAdapter` [in]

Handle that identifies the adapter.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbIndicateConnectorChange** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)