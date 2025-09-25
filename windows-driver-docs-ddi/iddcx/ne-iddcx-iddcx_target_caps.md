## Description

An **IDDCX_TARGET_CAPS** enumeration value identifies the capabilities of a target.

## Constants

### `IDDCX_TARGET_CAPS_NONE:0`

The target doesn't support any of the available capabilities.

### `IDDCX_TARGET_CAPS_WIDE_COLOR_SPACE:0x1`

If set, the driver has the ability to transform RGB values from the gamut defined by the sRGB/709 primaries to the monitor's primaries. The driver can also send any necessary control signaling to the monitor to indicate the correct interpretation of the pixel data being sent. This includes handling signed input in the range (-2.0 to 2.0). The driver must do this with all supported input surface formats, including 8888 and FP16.

### `IDDCX_TARGET_CAPS_HIGH_COLOR_SPACE:0x2`

If set, the driver supports all of the above WideColorSpace gamut functionality and also has the ability to apply the appropriate transfer curve for that display. This means accepting canonical color space data in the range [-128.0 to 256.0] and sending any necessary control signaling to the connected display to indicate the correct interpretation.

Setting **IDDCX_TARGET_CAPS_HIGH_COLOR_SPACE** is not a replacement for setting **IDDCX_TARGET_CAPS_WIDE_COLOR_SPACE**. Drivers that support **IDDCX_TARGET_CAPS_HIGH_COLOR_SPACE** should also set **IDDCX_TARGET_CAPS_WIDE_COLOR_SPACE**.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info)

[**IDARG_OUT_QUERYTARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytarget_info)