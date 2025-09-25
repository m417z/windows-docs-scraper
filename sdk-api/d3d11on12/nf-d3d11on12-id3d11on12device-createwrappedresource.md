# ID3D11On12Device::CreateWrappedResource

## Description

This method creates D3D11 resources for use with D3D 11on12.

## Parameters

### `pResource12` [in]

Type: **IUnknown***

A pointer to an already-created D3D12 resource or heap.

### `pFlags11` [in]

Type: **const [D3D11_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11on12/ns-d3d11on12-d3d11_resource_flags)***

A [D3D11_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11on12/ns-d3d11on12-d3d11_resource_flags) structure that enables an application to override flags that would be inferred by the resource/heap properties.
The D3D11_RESOURCE_FLAGS structure contains bind flags, misc flags, and CPU access flags.

### `InState`

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states)**

The use of the resource on input, as a bitwise-OR'd combination of [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) enumeration constants.

### `OutState`

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states)**

The use of the resource on output, as a bitwise-OR'd combination of [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) enumeration constants.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the wrapped resource interface.
The **REFIID**, or **GUID**, of the interface to the wrapped resource can be obtained by using the __uuidof() macro.
For example, __uuidof([ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)) will get the **GUID** of the interface to a wrapped resource.

### `ppResource11` [out, optional]

Type: **void****

After the method returns, points to the newly created wrapped D3D11 resource or heap.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D11On12Device](https://learn.microsoft.com/windows/desktop/api/d3d11on12/nn-d3d11on12-id3d11on12device)