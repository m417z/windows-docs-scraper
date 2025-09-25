# ID3D12StateObjectProperties::GetPipelineStackSize

## Description

Gets the current pipeline stack size.

## Return value

The current pipeline stack size in bytes. When called on non-executable state objects, such as collections, the return value is 0.

## Remarks

This method and [SetPipelineStackSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12stateobjectproperties-setpipelinestacksize) are not re-entrant. This means if calling either or both from separate threads, the app must synchronize on its own.

## See also

[ID3D12StateObjectProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobjectproperties)