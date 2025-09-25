## Description

The **IDDCX_WIRE_BITS_PER_COMPONENT** structure identifies the dithering support of a target.

## Members

### `Rgb`

An [**IDDCX_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component) value that describes the supported/requested pixel encoding using RGB sample format.

### `YCbCr444`

An [**IDDCX_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component) value that describes the supported/requested pixel encoding using YCbCr 4:4:4 sample format.

### `YCbCr422`

An [**IDDCX_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component) value that describes the supported/requested pixel encoding using YCbCr 4:2:2 sample format.

### `YCbCr420`

An [**IDDCX_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component) value that describes the supported/requested pixel encoding using YCbCr 4:2:0 sample format.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info)

[**IDARG_OUT_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytarget_info)