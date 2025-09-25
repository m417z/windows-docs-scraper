# ID3D11DeviceContext::SOSetTargets

## Description

Set the target output buffers for the stream-output stage of the pipeline.

## Parameters

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of buffer to bind to the device. A maximum of four output buffers can be set. If less than four are defined by the call, the remaining buffer slots are set to **NULL**. See Remarks.

### `ppSOTargets` [in, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11buffer)***

The array of output buffers (see [ID3D11Buffer](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11buffer)) to bind to the device. The buffers must have been created with the [D3D11_BIND_STREAM_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pOffsets` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)***

Array of offsets to the output buffers from *ppSOTargets*, one offset for each buffer. The offset values must be in bytes.

## Remarks

An offset of -1 will cause the stream output buffer to be appended, continuing after the last location written to the buffer in a previous stream output pass.

Calling this method using a buffer that is currently bound for writing will effectively bind **NULL** instead because a buffer cannot be bound as both an input and an output at the same time.

The debug layer will generate a warning whenever a resource is prevented from being bound simultaneously as an input and an output, but this will not prevent invalid data from being used by the runtime.

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

Note that unlike some other resource methods in Direct3D, all currently bound targets will be unbound by calling `SOSetTargets(0, nullptr, nullptr);`.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11devicecontext)