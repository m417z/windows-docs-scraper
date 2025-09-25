# EVT_IDD_CX_ADAPTER_INIT_FINISHED callback function

## Description

**EVT_IDD_CX_ADAPTER_INIT_FINISHED** is called by the OS to inform the driver that the adapter initialization has completed.

## Parameters

### `AdapterObject`

[in] A handle provided by the driver used by the OS to reference the adapter in a call to the driver.

### `pInArgs`

[in] A pointer to a [**IDARG_IN_ADAPTER_INIT_FINISHED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init_finished) structure.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.