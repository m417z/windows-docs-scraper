# D3DKMTCheckExclusiveOwnership function

## Description

The **D3DKMTCheckExclusiveOwnership** function checks whether any kernel device object in the operating system has an exclusive level of ownership of any video present sources.

## Return value

**D3DKMTCheckExclusiveOwnership** returns a Boolean value that indicates **TRUE** if any kernel device object in the operating system has an exclusive level of ownership of any video present sources and **FALSE** otherwise.

## Remarks

For a description of ownership levels of video present sources, see the [D3DKMTSetVidPnSourceOwner](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner) function and the [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) structure. An exclusive level of ownership is represented by the D3DKMT_VIDPNSOURCEOWNER_EXCLUSIVE or D3DKMT_VIDPNSOURCEOWNER_EXCLUSIVEGDI owner type, which can be specified in one of the elements in the array that the **pType** member of D3DKMT_SETVIDPNSOURCEOWNER specifies.

## See also

[D3DKMTSetVidPnSourceOwner](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner)

[D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner)