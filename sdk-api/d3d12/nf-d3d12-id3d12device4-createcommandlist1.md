## Description

Creates a command list in the closed state. Also see [ID3D12Device::CreateCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandlist).

## Parameters

### `nodeMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single-GPU operation, set this to zero. If there are multiple GPU nodes, then set a bit to identify the node (the device's physical adapter) for which to create the command list. Each bit in the mask corresponds to a single node. Only one bit must be set. Also see [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `type` [in]

Type: **[D3D12_COMMAND_LIST_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_type)**

Specifies the type of command list to create.

### `flags`

Type: **[D3D12_COMMAND_LIST_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_flags)**

Specifies creation flags.

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

## See also

[ID3D12Device::CreateCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandlist)