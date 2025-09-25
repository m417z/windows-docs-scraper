# ID3D12GraphicsCommandList::SOSetTargets

## Description

Sets the stream output buffer views.

## Parameters

### `StartSlot` [in]

Type: **UINT**

Index into the device's zero-based array to begin setting stream output buffers.

### `NumViews` [in]

Type: **UINT**

The number of entries in the *pViews* array.

### `pViews` [in, optional]

Type: **const [D3D12_STREAM_OUTPUT_BUFFER_VIEW](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_stream_output_buffer_view)***

Specifies an array of [D3D12_STREAM_OUTPUT_BUFFER_VIEW](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_stream_output_buffer_view) structures.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)