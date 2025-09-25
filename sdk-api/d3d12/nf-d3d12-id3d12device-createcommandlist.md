## Description

Creates a command list.

## Parameters

### `nodeMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single-GPU operation, set this to zero. If there are multiple GPU nodes, then set a bit to identify the node (the device's physical adapter) for which to create the command list. Each bit in the mask corresponds to a single node. Only one bit must be set. Also see [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `type` [in]

Type: **[D3D12_COMMAND_LIST_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_type)**

Specifies the type of command list to create.

### `pCommandAllocator` [in]

Type: **[ID3D12CommandAllocator](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandallocator)\***

A pointer to the command allocator object from which the device creates command lists.

### `pInitialState` [in, optional]

Type: **[ID3D12PipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinestate)\***

An optional pointer to the pipeline state object that contains the initial pipeline state for the command list. If it is `nullptr`, then the runtime sets a dummy initial pipeline state, so that drivers don't have to deal with undefined state. The overhead for this is low, particularly for a command list, for which the overall cost of recording the command list likely dwarfs the cost of a single initial state setting. So there's little cost in not setting the initial pipeline state parameter, if doing so is inconvenient.

For bundles, on the other hand, it might make more sense to try to set the initial state parameter (since bundles are likely smaller overall, and can be reused frequently).

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the command list interface to return in *ppCommandList*.

### `ppCommandList` [out]

Type: **void\*\***

A pointer to a memory block that receives a pointer to the [ID3D12CommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandlist) or [ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist) interface for the command list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_OUTOFMEMORY|There is insufficient memory to create the command list.|

See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The device creates command lists from the command allocator.

## Examples

The [D3D12Bundles](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12Device::CreateCommandList** as follows.

Create the pipeline objects.

```cpp
ComPtr<ID3D12CommandAllocator> m_commandAllocator;
ComPtr<ID3D12GraphicsCommandList> m_commandList;
```

Create a command allocator.

```cpp
ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
```

Creating the direct command list.

```cpp
ThrowIfFailed(m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_commandList)));
```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)

[ID3D12GraphicsCommandList::Reset](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-reset)