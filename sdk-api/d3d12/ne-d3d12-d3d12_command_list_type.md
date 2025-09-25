# D3D12_COMMAND_LIST_TYPE enumeration

## Description

Specifies the type of a command list.

## Constants

### `D3D12_COMMAND_LIST_TYPE_DIRECT:0`

Specifies a command buffer that the GPU can execute. A direct command list doesn't inherit any GPU state.

### `D3D12_COMMAND_LIST_TYPE_BUNDLE:1`

Specifies a command buffer that can be executed only directly via a direct command list. A bundle command list inherits all GPU state (except for the currently set pipeline state object and primitive topology).

### `D3D12_COMMAND_LIST_TYPE_COMPUTE:2`

Specifies a command buffer for computing.

### `D3D12_COMMAND_LIST_TYPE_COPY:3`

Specifies a command buffer for copying.

### `D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE:4`

Specifies a command buffer for video decoding.

### `D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS:5`

Specifies a command buffer for video processing.

## Remarks

This enum is used by the following methods:

* [CreateCommandAllocator](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommandallocator)
* [CreateCommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommandqueue)
* [CreateCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommandlist)

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)