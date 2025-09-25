# ID3D10Device::SOSetTargets

## Description

Set the target output [buffers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) for the [StreamOutput](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage) stage, which enables/disables the pipeline to stream-out data.

## Parameters

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of buffer to bind to the device. A maximum of four output buffers can be set. If less than four are defined by the call, the remaining buffer slots are set to **NULL**. See Remarks.

### `ppSOTargets` [in]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)***

The array of output buffers (see [ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)) to bind to the device. The buffers must have been created with the [D3D10_BIND_STREAM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) flag.

### `pOffsets` [in]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Array of offsets to the output buffers from *ppSOTargets*, one offset for each buffer. The offset values must be in bytes.

## Remarks

Call **ID3D10Device::SOSetTargets** (before any draw calls) to stream data out; call SOSetTargets with **NULL** to stop streaming data out. For an example, see Exercise 01 from the GDC 2007 workshop, which sets the stream output rendertargets before calling draw methods in the RenderInstanceToStream function.

An offset of -1 will cause the stream output buffer to be appended, continuing after the last location written to the buffer in a previous stream output pass.

Calling this method using a buffer that is currently bound for writing will effectively bind **NULL** instead because a buffer cannot be bound as both an input and an output at the same time.

The [Debug Layer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers) will generate a warning whenever a resource is prevented from being bound simultaneously as an input and an output, but this will not prevent invalid data from being used by the runtime.

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)