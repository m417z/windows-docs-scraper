# ID3D11Device5::CreateFence

## Description

Creates a fence object.

This member function is equivalent to the Direct3D 12 [ID3D12Device::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createfence) member function, and applies between Direct3D 11 and Direct3D 12 in interop scenarios.

## Parameters

### `InitialValue`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The initial value for the fence.

### `Flags`

Type: **[D3D11_FENCE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_fence_flag)**

A combination of [D3D11_FENCE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_fence_flag)-typed values that are combined by using a bitwise OR operation.
The resulting value specifies options for the fence.

### `ReturnedInterface`

Type: **REFIID**

The globally unique identifier (**GUID**) for the fence interface ([ID3D11Fence](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11fence)).
The **REFIID**, or **GUID**, of the interface to the fence can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D11Fence) will get the **GUID** of the interface to a fence.

### `ppFence` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D11Fence](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11fence) interface that is used to access the fence.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Device5](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11device5)

[UnregisterDeviceRemoved](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11device4-unregisterdeviceremoved)