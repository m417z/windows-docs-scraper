## Description

The OS calls an indirect display driver's **EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO** callback function to retrieve information about target capabilities.

## Parameters

### `AdapterObject`

[in] The adapter object of the adapter being queried. This adapter object was returned in a call to [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync).

### `pInArgs`

[in] A pointer to an [**IDARG_IN_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_querytarget_info) structure containing input arguments for this function.

### `pOutArgs`

[out] A pointer to an [**IDARG_OUT_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytarget_info) structure containing output arguments for this function.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, the callback should return an appropriate NTSTATUS error code.

## Remarks

The OS calls **EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO** after a driver calls [**IddCxMonitorArrival**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorarrival). The OS uses the connector index provided by the driver in the [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate) call for this monitor.

Specifying [**IDDCX_BITS_PER_COMPONENT_NONE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component) is valid; however, to enable HDR, current Windows policies require either the ability to send 10 or more bits per component to a monitor or alternatively for the driver to support dithering of more than 8 bits per component down to 8 bits per component. The ability to dither allows HDR to be supported at 4K resolutions over HDMI 2.0.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_querytarget_info)

[**IDARG_OUT_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytarget_info)

[**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync)

[**IddCxMonitorArrival**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorarrival)

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)