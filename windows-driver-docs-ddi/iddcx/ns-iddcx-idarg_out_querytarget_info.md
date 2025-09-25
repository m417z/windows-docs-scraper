## Description

The **IDARG_OUT_QUERYTARGET_INFO** structure contains output arguments for the [**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info) callback function.

## Members

### `TargetCaps`

An [**IDDCX_TARGET_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_target_caps) value that identifies the capabilities of the target.

### `DitheringSupport`

An [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) structure that identifies the dithering support. The driver should set the wire-format bit for each format where the driver and hardware supports dithering that is beneficial to image quality when the source pixel format is higher precision than the wire-format.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info)

[**IDDCX_TARGET_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_target_caps)

[**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component)