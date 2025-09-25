# D3D12DDI_RESOURCE_STATES enumeration

## Description

Contains resource states. Resource barriers allow transitioning between hardware specific states for a corresponding operation and to synchronize read after write. Resource barriers are an existing concept in D3D12 that is extended to support video decode and video process by adding these usage flags.

## Constants

### `D3D12DDI_RESOURCE_STATE_COMMON:0x00000000`

Common.

### `D3D12DDI_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER:0x00000001`

Vertex and constant buffer.

### `D3D12DDI_RESOURCE_STATE_INDEX_BUFFER:0x00000002`

Index buffer.

### `D3D12DDI_RESOURCE_STATE_RENDER_TARGET:0x00000004`

Render target.

### `D3D12DDI_RESOURCE_STATE_UNORDERED_ACCESS:0x00000008`

Unordered access.

### `D3D12DDI_RESOURCE_STATE_DEPTH_WRITE:0x00000010`

Depth write.

### `D3D12DDI_RESOURCE_STATE_DEPTH_READ:0x00000020`

Depth read.

### `D3D12DDI_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE:0x00000040`

Non-pixel shader resource.

### `D3D12DDI_RESOURCE_STATE_PIXEL_SHADER_RESOURCE:0x00000080`

Pixel shader resource.

### `D3D12DDI_RESOURCE_STATE_STREAM_OUT:0x00000100`

Stream out.

### `D3D12DDI_RESOURCE_STATE_INDIRECT_ARGUMENT:0x00000200`

Indirect argument.

### `D3D12DDI_RESOURCE_STATE_COPY_DEST:0x00000400`

Copy destination.

### `D3D12DDI_RESOURCE_STATE_COPY_SOURCE:0x00000800`

Copy source.

### `D3D12DDI_RESOURCE_STATE_RESOLVE_DEST:0x00001000`

Resolve destination.

### `D3D12DDI_RESOURCE_STATE_RESOLVE_SOURCE:0x00002000`

Resolve source.

### `D3D12DDI_RESOURCE_STATE_0020_VIDEO_DECODE_READ:0x00010000`

Video decode read. The read state is used for reading references during decode and also used for inputs to process frame. This state is only valid in the decode and process command list.

### `D3D12DDI_RESOURCE_STATE_0020_VIDEO_DECODE_WRITE:0x00020000`

Video decode write. The write state is used for the decode target, or destination surface of the process frame. The write state is also used when decode conversion is enabled for the non-converted reference. This state is only valid in the decode and process command list.

### `D3D12DDI_RESOURCE_STATE_0020_VIDEO_PROCESS_READ:0x00040000`

Video process read.

### `D3D12DDI_RESOURCE_STATE_0020_VIDEO_PROCESS_WRITE:0x00080000`

Video process write.

### `D3D12DDI_RESOURCE_STATE_0060_VIDEO_ENCODE_READ:0x00200000`

Video encode read resource state.

### `D3D12DDI_RESOURCE_STATE_0060_VIDEO_ENCODE_WRITE:0x00800000`

Video encode write resource state.

### `D3D12DDI_RESOURCE_STATE_0062_SHADING_RATE_SOURCE:0x01000000`

Shading rate source resource state.

Available starting in WDDM 2.6.

### `D3D12DDI_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE:0x400000`

Ray tracing acceleration structure resource state.

## Remarks

Resource barriers allow transitioning between hardware specific states for a corresponding operation and to synchronize read after write.

Resource barriers are an existing concept in D3D12 that is extended to support video decode by adding new usage flags.
The write state is used for the decode target. The write state is also used when decode conversion is enabled for the non-converted reference.