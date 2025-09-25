# ID3D12StateObjectProperties::SetPipelineStackSize

## Description

Set the current pipeline stack size.

## Parameters

### `PipelineStackSizeInBytes`

Stack size in bytes to use during pipeline execution for each shader thread. There can be many thousands of threads in flight at once on the GPU.

If the value is greater than 0xffffffff (the maximum value of a 32-bit UINT) the runtime will drop the call, and the debug layer will print an error, as this is likely the result of summing up invalid stack sizes returned from [GetShaderStackSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12stateobjectproperties-getshaderstacksize) called with invalid parameters, which return 0xffffffff. In this case, the previously set stack size, or the default, remains.

## Remarks

This method and [GetPipelineStackSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12stateobjectproperties-getpipelinestacksize) are not re-entrant. This means if calling either or both from separate threads, the app must synchronize on its own.

The runtime drops calls to state objects other than raytracing pipelines, such as collections.

## See also

[ID3D12StateObjectProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobjectproperties)