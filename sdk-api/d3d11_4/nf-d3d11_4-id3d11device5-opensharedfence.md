# ID3D11Device5::OpenSharedFence

## Description

Opens a handle for a shared fence by using HANDLE and REFIID.

This member function is a limited version of the Direct3D 12 [ID3D12Device::OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-opensharedhandle) member function, and applies between Direct3D 11 and Direct3D 12 in interop scenarios. Unlike **ID3D12Device::OpenSharedHandle** which operates on resources, heaps, and fences, the **ID3D11Device5::OpenSharedFence** function only operates on fences; in Direct3D 11, shared resources are opened with the [ID3D11Device::OpenSharedResource1](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) member function.

## Parameters

### `hFence` [in]

Type: **HANDLE**

The handle that was returned by a call to [ID3D11Fence::CreateSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d11_3/nf-d3d11_3-id3d11fence-createsharedhandle) or [ID3D12Device::CreateSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createsharedhandle).

### `ReturnedInterface`

Type: **REFIID**

The globally unique identifier (**GUID**) for the [ID3D11Fence](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11fence) interface. The **REFIID**, or **GUID**, of the interface can be obtained by using the __uuidof() macro. For example, __uuidof(ID3D11Fence) will get the **GUID** of the interface to the fence.

### `ppFence` [out, optional]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D11Fence](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11fence) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Device5](https://learn.microsoft.com/windows/win32/api/d3d11_4/nn-d3d11_4-id3d11device5), [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine)