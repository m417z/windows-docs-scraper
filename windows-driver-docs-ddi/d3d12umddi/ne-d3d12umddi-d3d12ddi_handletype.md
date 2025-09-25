# D3D12DDI_HANDLETYPE enumeration

## Description

A **D3D12DDI_HANDLETYPE** value identifies a driver handle type.

## Constants

### `D3D12DDI_HT_COMMAND_QUEUE:19`

A command queue handle type.

### `D3D12DDI_HT_COMMAND_ALLOCATOR:20`

A command allocator handle type.

### `D3D12DDI_HT_PIPELINE_STATE:21`

A pipeline state handle type.

### `D3D12DDI_HT_COMMAND_LIST:22`

A command list handle type.

### `D3D12DDI_HT_FENCE:23`

A fence handle type.

### `D3D12DDI_HT_DESCRIPTOR_HEAP:24`

A descriptor heap handle type.

### `D3D12DDI_HT_HEAP:25`

A heap handle type.

### `D3D12DDI_HT_QUERY_HEAP:27`

A query heap handle type.

### `D3D12DDI_HT_COMMAND_SIGNATURE:28`

A command signature handle type.

### `D3D12DDI_HT_0010_PIPELINE_LIBRARY:29`

A pipeline library handle type.

### `D3D12DDI_HT_0020_VIDEO_DECODER:30`

A video decoder handle type.

### `D3D12DDI_HT_0020_VIDEO_PROCESSOR:32`

A video processor handle type.

### `D3D12DDI_HT_0012_RESOURCE:34`

A resource handle type.

### `D3D12DDI_HT_PASS:35`

A pass handle type.

### `D3D12DDI_HT_0030_CRYPTOSESSION:36`

A crypto session handle type.

### `D3D12DDI_HT_0030_CRYPTOSESSIONPOLICY:37`

A crypto session policy handle type.

### `D3D12DDI_HT_0030_PROTECTEDRESOURCESESSION:38`

A protected resource session handle type.

### `D3D12DDI_HT_0032_VIDEO_DECODER_HEAP:39`

A video decoder heap handle type.

### `D3D12DDI_HT_0040_COMMAND_POOL:40`

A command pool.

### `D3D12DDI_HT_0040_COMMAND_RECORDER:41`

A command recorder.

### `D3D12DDI_HT_0054_STATE_OBJECT:42`

A state object.

### `D3D12DDI_HT_METACOMMAND:43`

A meta-command.

### `D3D12DDI_HT_0050_SCHEDULINGGROUP:44`

Hardware scheduling group.

### `D3D12DDI_HT_0053_VIDEO_MOTION_ESTIMATOR:45`

Video motion estimator.

### `D3D12DDI_HT_0053_VIDEO_MOTION_VECTOR_HEAP:46`

Video motion vector heap.

### `D3D12DDI_HT_0061_VIDEO_EXTENSION_COMMAND:47`

The handle type for Video Extension Commands. Used in DDI such as pfnMakeResident and pfnEvict that can accept multiple handle types.

The UMD handle type declaration is `D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063`.

This field is available starting in Windows 10, version 1903 and UMD DDI Min Version D3D12DDI_SUPPORTED_0043.

### `D3D12DDI_HT_0080_VIDEO_ENCODER:48`

Handle type for a video encoder.

### `D3D12DDI_HT_0080_VIDEO_ENCODER_HEAP:49`

Handle type for a video encoder heap.