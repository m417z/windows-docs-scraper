# _D3DDDI_MULTISAMPLINGMETHOD structure

## Description

The D3DDDI_MULTISAMPLINGMETHOD structure describes a multiple-sampling method.

## Members

### `NumSamples` [out]

The number of subpixels that are used in the multiple-sampling method (for example, 2 for 2x and 8 for 8x multiple-sampling).

### `NumQualityLevels` [out]

The upper bound on the quality range that is supported for the multiple-sampling method. The range includes values from 0 through the reported maximum quality setting.

## Remarks

The driver can partition its quality levels for a given multiple-sampling method into as many increments as it requires; however, each incremental step noticeably improves quality of the presented image.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXGKARG_DESCRIBEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_describeallocation)

[DxgkDdiDescribeAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_describeallocation)