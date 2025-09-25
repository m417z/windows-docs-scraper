# D3D11_COMPUTE_SHADER_TRACE_DESC structure

## Description

Describes an instance of a compute shader to trace.

## Members

### `Invocation`

The invocation number of the instance of the compute shader.

### `ThreadIDInGroup`

The [SV_GroupThreadID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sv-groupthreadid) to trace. This value identifies indexes of individual threads within a thread group that a compute shader executes in.

### `ThreadGroupID`

The [SV_GroupID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sv-groupid) to trace. This value identifies indexes of a thread group that the compute shader executes in.

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)