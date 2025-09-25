# _D3DKMT_DEBUG_SNAPSHOT_ESCAPE structure

## Description

 Do not use the D3DKMT_DEBUG_SNAPSHOT_ESCAPE structure; it is for testing purposes only.

The D3DKMT_DEBUG_SNAPSHOT_ESCAPE structure describes a debug snapshot that is returned in a call to the [D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Members

### `Length` [out]

The actual length of the snapshot written in the **Buffer** member.

### `Buffer` [out]

The buffer to place the snapshot in.

## See also

[D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)