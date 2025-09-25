# ID3D12CommandQueue::SetMarker

## Description

Not intended to be called directly. Use the
[PIX event runtime](https://devblogs.microsoft.com/pix/winpixeventruntime/) to insert events into a command queue.

## Parameters

### `Metadata`

Type: **UINT**

Internal.

### `pData` [in, optional]

Type: **const void***

Internal.

### `Size`

Type: **UINT**

Internal.

## Remarks

This is a support method used internally by the PIX event runtime. It is not intended to be called directly.

To insert instrumentation markers at the current location within a D3D12 command queue, use the **PIXSetMarker** function. This is provided by the [WinPixEventRuntime](https://devblogs.microsoft.com/pix/winpixeventruntime/) NuGet package.

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)