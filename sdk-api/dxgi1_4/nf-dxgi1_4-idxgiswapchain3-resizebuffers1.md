# IDXGISwapChain3::ResizeBuffers1

## Description

Changes the swap chain's back buffer size, format, and number of buffers, where the swap chain was created using a D3D12 command queue as an input device.
This should be called when the application window is resized.

## Parameters

### `BufferCount` [in]

Type: **UINT**

The number of buffers in the swap chain (including all back and front buffers).
This number can be different from the number of buffers with which you created the swap chain.
This number can't be greater than **DXGI_MAX_SWAP_CHAIN_BUFFERS**.
Set this number to zero to preserve the existing number of buffers in the swap chain.
You can't specify less than two buffers for the flip presentation model.

### `Width` [in]

Type: **UINT**

The new width of the back buffer.
If you specify zero, DXGI will use the width of the client area of the target window.
You can't specify the width as zero if you called the [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) method to create the swap chain for a composition surface.

### `Height` [in]

Type: **UINT**

The new height of the back buffer.
If you specify zero, DXGI will use the height of the client area of the target window.
You can't specify the height as zero if you called the [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) method to create the swap chain for a composition surface.

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the new format of the back buffer.
Set this value to [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) to preserve the existing format of the back buffer.
The flip presentation model supports a more restricted set of formats than the bit-block transfer (bitblt) model.

### `SwapChainFlags` [in]

Type: **UINT**

A combination of [DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_chain_flag)-typed values that are combined by using a bitwise OR operation.
The resulting value specifies options for swap-chain behavior.

### `pCreationNodeMask` [in]

Type: **const UINT***

An array of UINTs, of total size *BufferCount*, where the value indicates which node the back buffer should be created on.
Buffers created using **ResizeBuffers1** with a non-null *pCreationNodeMask* array are visible to all nodes.

### `ppPresentQueue` [in]

Type: **IUnknown***

An array of command queues ([ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) instances), of total size *BufferCount*.
Each queue provided must match the corresponding creation node mask specified in the *pCreationNodeMask* array.
When **Present()** is called, in addition to rotating to the next buffer for the next frame, the swapchain will also rotate through these command queues.
This allows the app to control which queue requires synchronization for a given present operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise.
For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

## Remarks

This method is only valid to call when the swapchain was created using a D3D12 command queue ([ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)) as an input device.

When a swapchain is created on a multi-GPU adapter, the backbuffers are all created on node 1 and only a single command queue is supported.
**ResizeBuffers1** enables applications to create backbuffers on different nodes, allowing a different command queue to be used with each node.
These capabilities enable Alternate Frame Rendering (AFR) techniques to be used with the swapchain.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

Also see the Remarks section in [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers), all of which is relevant to **ResizeBuffers1**.

## See also

[IDXGISwapChain3](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nn-dxgi1_4-idxgiswapchain3)