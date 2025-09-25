# ID3D12GraphicsCommandList::EndEvent

## Description

Not intended to be called directly. Use the
[PIX event runtime](https://devblogs.microsoft.com/pix/winpixeventruntime/) to insert events into a command list.

## Remarks

This is a support method used internally by the PIX event runtime. It is not intended to be called directly.

To mark the end of an instrumentation region at the current location within a D3D12 command list, use the **PIXEndEvent** function or **PIXScopedEvent** macro. These are provided by the [WinPixEventRuntime](https://devblogs.microsoft.com/pix/winpixeventruntime/) NuGet package.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)