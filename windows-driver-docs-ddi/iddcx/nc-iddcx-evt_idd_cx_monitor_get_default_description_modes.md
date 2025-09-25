# EVT_IDD_CX_MONITOR_GET_DEFAULT_DESCRIPTION_MODES callback function

## Description

**EVT_IDD_CX_MONITOR_GET_DEFAULT_DESCRIPTION_MODES** is called by the OS to request the default monitor mode list from the driver for the specified monitor when a monitor without a description is connected.

## Parameters

### `MonitorObject`

[in] A handle by the OS to identify the monitor that requires a generated list of default modes.

### `pInArgs`

[in] A pointer to a [IDARG_IN_GETDEFAULTDESCRIPTIONMODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_getdefaultdescriptionmodes) structure to be used by the driver.

### `pOutArgs`

[out] A pointer to a [IDARG_OUT_GETDEFAULTDESCRIPTIONMODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getdefaultdescriptionmodes) structure for the driver to fill.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The driver must create at least one monitor mode for the monitor description.