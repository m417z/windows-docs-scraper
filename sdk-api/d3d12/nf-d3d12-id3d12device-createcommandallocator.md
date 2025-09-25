# ID3D12Device::CreateCommandAllocator

## Description

Creates a command allocator object.

## Parameters

### `type` [in]

Type: **[D3D12_COMMAND_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type)**

A [D3D12_COMMAND_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type)-typed value that specifies the type of command allocator to create.
The type of command allocator can be the type that records either direct command lists or bundles.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the command allocator interface ([ID3D12CommandAllocator](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandallocator)).
The **REFIID**, or **GUID**, of the interface to the command allocator can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D12CommandAllocator) will get the **GUID** of the interface to a command allocator.

### `ppCommandAllocator` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D12CommandAllocator](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandallocator) interface for the command allocator.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the command allocator.
See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The device creates command lists from the command allocator.

#### Examples

The [D3D12Bundles](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::CreateCommandAllocator** as follows:

```cpp
ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)