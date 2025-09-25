## Description

The OS calls **EVT_IDD_CX_ADAPTER_COMMIT_MODES2** to inform the driver of a mode change for monitors on the adapter.

## Parameters

### `AdapterObject`

[in] The OS-generated adapter object of the adapter being queried. This [**IDDCX_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects#iddcx_adapter) object handle was returned in a previous call to [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync).

### `pInArgs`

[in] Pointer to a [**IDARG_IN_COMMITMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes2) structure that contains arguments used by **EVT_IDD_CX_ADAPTER_COMMIT_MODES2**.

## Return value

**EVT_IDD_CX_ADAPTER_COMMIT_MODES2** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

When modes are committed for monitors, IddCx version 1.10 drivers that support HDR or WCG are called via this function and told the color space and bits per component to be used on the physical monitor connection. These values are based on the target capabilities and mode parameters previously reported by the driver. Reporting [adapter support for FP16](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) but not exposing this function is an error.

The color space specified in a committed mode does not specify the surface format used for every surface in a swapchain. The surface provided in [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) must still be queried.

The OS always provides the [**IDDCX_PATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2) for every connected monitor even if that monitor isn't active, and indicates which paths have changed. If a path is marked inactive, then the whole display pipeline for that path will be powered off and no signal will be sent to the monitor.

When a new path is committed, the driver should program the display pipeline to display a black image until the first frame is ready to be displayed. To achieve this, WDDM visibility should be off until the first frame is ready to be displayed, then the visibility should be turned on.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_COMMITMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes2)

[**IDDCX_PATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2)

[**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2)