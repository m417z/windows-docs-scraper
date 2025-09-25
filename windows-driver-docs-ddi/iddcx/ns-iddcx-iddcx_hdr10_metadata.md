## Description

The **IDDCX_HDR10_METADATA** structure contains the HDR10 metadata.

## Members

### `RedPrimary[2]`

The chromaticity coordinates of the red value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000; that is, 1 == 0.00002.

### `GreenPrimary[2]`

The chromaticity coordinates of the green value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000; that is, 1 == 0.00002.

### `BluePrimary[2]`

The chromaticity coordinates of the blue value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000; that is, 1 == 0.00002.

### `WhitePoint[2]`

The chromaticity coordinates of the white point in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000; that is, 1 == 0.00002.

### `MaxMasteringLuminance`

The maximum number of nits of the display used to master the content. This value is in whole nits.

### `MinMasteringLuminance`

The minimum number of nits of the display used to master the content. The value is normalized to 10,000, i.e. 1 == 0.0001.

### `MaxContentLightLevel`

The maximum content light level (MaxCLL). This is the nit value corresponding to the brightest pixel used anywhere in the content. This value is in whole nits.

### `MaxFrameAverageLightLevel`

The maximum frame average light level (MaxFALL). This is the nit value corresponding to the average luminance of the frame that has the brightest average luminance anywhere in the content. This value is in whole nits.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata)

[**IDARG_IN_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_monitor_set_default_hdr_metadata)

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)