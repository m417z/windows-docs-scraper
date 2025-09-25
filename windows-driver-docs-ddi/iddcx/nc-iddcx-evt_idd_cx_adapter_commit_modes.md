# EVT_IDD_CX_ADAPTER_COMMIT_MODES callback function

## Description

The OS calls **EVT_IDD_CX_ADAPTER_COMMIT_MODES** to inform the driver of a mode change for monitors on the adapter.

## Parameters

### `AdapterObject`

[in] A driver-provided [**IDDCX_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects#iddcx_adapter) handle that is used by the OS to reference the adapter in a call to the driver.

### `pInArgs`

[in] Pointer to a [**IDARG_IN_COMMITMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes) structure that contains arguments used by **EVT_IDD_CX_ADAPTER_COMMIT_MODES**.

## Return value

**EVT_IDD_CX_ADAPTER_COMMIT_MODES** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

The OS always provides the [**IDDCX_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path) for every connected monitor even if that monitor isn't active, and indicates which paths have changed. If a path is marked inactive, then the whole display pipeline for that path will be powered off and no signal will be sent to the monitor.

When a new path is committed, the driver should program the display pipeline to display a black image until the first frame is ready to be displayed. To achieve this, WDDM visibility should be off until the first frame is ready to be displayed, then the visibility should be turned on.

## See also

[**IDARG_IN_COMMITMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes)