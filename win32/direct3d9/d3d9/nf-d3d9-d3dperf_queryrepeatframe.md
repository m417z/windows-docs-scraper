# D3DPERF_QueryRepeatFrame function

Determine whether a performance profiler is requesting that the current frame be resubmitted to Direct3D for performance analysis. This function is not currently supported by PIX.

## Return value

If the return value is TRUE, the caller should repeat the same sequence of calls. If FALSE, the caller should continue.

## Remarks

The function should be called immediately after **IDirect3DDevice9::Present** is called.

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | d3d9.h |
| **Library** | d3d9.lib |
| **DLL** | d3d9.dll |