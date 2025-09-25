# _D3DKMT_MULTISAMPLEMETHOD structure

## Description

The D3DKMT_MULTISAMPLEMETHOD structure describes a multiple-sampling method.

## Members

### `NumSamples` [out]

The number of subpixels that are used in the multiple-sampling method (for example, 2 for 2x and 8 for 8x multiple-sampling).

### `NumQualityLevels` [out]

The upper bound on the quality range that is supported for the multiple-sampling method. The range extends from zero through the reported maximum quality setting.

### `Reserved`

Reserved for internal use.

## Remarks

The driver can partition its quality levels for a given multiple-sampling method into as many increments as it requires, with the condition that each incremental step noticeably improves the quality of the presented image.

## See also

[D3DKMTGetMultisampleMethodList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetmultisamplemethodlist)

[D3DKMT_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getmultisamplemethodlist)