# ID3D12Device::OpenSharedHandle

## Description

Opens a handle for shared resources, shared heaps, and shared fences, by using HANDLE and REFIID.

## Parameters

### `NTHandle` [in]

Type: **HANDLE**

The handle that was output by the call to
[ID3D12Device::CreateSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createsharedhandle).

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for one of the following interfaces:

* [ID3D12Heap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap)
* [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)
* [ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)

The **REFIID**, or **GUID**, of the interface can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D12Heap) will get the **GUID** of the interface to a resource.

### `ppvObj` [out, optional]

Type: **void****

A pointer to a memory block that receives a pointer to one of the following interfaces:

* [ID3D12Heap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap)
* [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)
* [ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)

[Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine)