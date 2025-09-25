## Description

The **IDDCX_WIRE_FORMAT_INFO** structure contains details about the signal to send to the monitor.

## Members

### `ColorSpace`

An [**IDDCX_COLOR_SPACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_color_space) value that specifies the color space to use on the monitor.

### `BitsPerComponent`

An [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) value that specifies the number of bits per component and which pixel encoding to use on the monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2)

[**IDARG_IN_COMMITMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes2)

[**IDDCX_PATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2)