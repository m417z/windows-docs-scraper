# _D3DKMT_WORKINGSETINFO structure

## Description

The D3DKMT_WORKINGSETINFO structure describes information about the graphics adapter's working set that the OpenGL installable client driver (ICD) obtains by calling the [D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo) function.

## Members

### `Flags` [out]

A [D3DKMT_WORKINGSETFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_workingsetflags) structure that indicates, in bit-field flags, working-set properties.

### `MinimumWorkingSetPercentile` [out]

The minimum working-set percentile.

### `MaximumWorkingSetPercentile` [out]

The maximum working-set percentile.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[D3DKMT_WORKINGSETFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_workingsetflags)