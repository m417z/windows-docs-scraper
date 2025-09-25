## Description

The OS calls **EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA** to provide the default HDR10 metadata that a console driver should send to the monitor when default metadata is specified in a call to [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2).

## Parameters

### `MonitorObject`

[in] An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that is the OS context handle for the monitor. The OS provided this handle in a prior call to [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs`

[in] Pointer to an [**IDARG_IN_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_monitor_set_default_hdr_metadata) structure that contains the input arguments for this callback function.

## Return value

**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

The OS only calls this callback function for console drivers. It calls the driver for any monitor that supports HDR to tell the driver what default HDR metadata to use if the driver sets the [**IDDCX_ADAPTER_FLAGS_CAN_PROCESS_FP16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags). flag. This call occurs after [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate) is called and before any calls to [**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2). The driver should use this data whenever **IDDCX_HDRMETADATA_TYPE_DEFAULT** is specified as the metadata type in the [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) returned when calling [**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2). The OS can call the driver to update this default at any time.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_monitor_set_default_hdr_metadata)

[**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)