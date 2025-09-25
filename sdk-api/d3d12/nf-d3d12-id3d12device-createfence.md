# ID3D12Device::CreateFence

## Description

Creates a fence object.

## Parameters

### `InitialValue`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The initial value for the fence.

### `Flags`

Type: **[D3D12_FENCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fence_flags)**

A combination of [D3D12_FENCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fence_flags)-typed values that are combined by using a bitwise OR operation.
The resulting value specifies options for the fence.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the fence interface ([ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence)).
The **REFIID**, or **GUID**, of the interface to the fence can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D12Fence) will get the **GUID** of the interface to a fence.

### `ppFence` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence) interface that is used to access the fence.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)