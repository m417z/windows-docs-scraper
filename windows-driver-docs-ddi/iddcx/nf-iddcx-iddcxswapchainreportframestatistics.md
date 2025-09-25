# IddCxSwapChainReportFrameStatistics function

## Description

An OS callback function the driver calls to report the frame statistics after it has processed a frame completely.

## Parameters

### `SwapChainObject` [in]

The swap-chain object whose frame statistics are being reported.

### `pInArgs` [in]

Pointer to a [**IDARG_IN_REPORTFRAMESTATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_reportframestatistics) structure.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## See also

[**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain)
[**EVT_IDD_CX_MONITOR_UNASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_unassign_swapchain)