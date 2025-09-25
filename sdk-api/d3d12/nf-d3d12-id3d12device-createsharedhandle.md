# ID3D12Device::CreateSharedHandle

## Description

Creates a shared handle to a heap, resource, or fence object.

## Parameters

### `pObject` [in]

Type: **[ID3D12DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12devicechild)***

A pointer to the [ID3D12DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12devicechild) interface that represents the heap, resource, or fence object to create for sharing.
The following interfaces (derived from **ID3D12DeviceChild**) are supported:

* [ID3D12Heap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12heap)
* [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)
* [ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence)

### `pAttributes` [in, optional]

Type: **const [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)***

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that contains two separate but related data members: an optional security descriptor, and a **Boolean** value that determines whether child processes can inherit the returned handle.

Set this parameter to **NULL** if you want child processes that the
application might create to not inherit the handle returned by
**CreateSharedHandle**, and if you want the resource that is associated with the returned handle to get a default security
descriptor.

The **lpSecurityDescriptor** member of the structure specifies a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) for the resource.
Set this member to **NULL** if you want the runtime to assign a default security descriptor to the resource that is associated with the returned handle.
The ACLs in the default security descriptor for the resource come from the primary or impersonation token of the creator.
For more info, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `Access`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Currently the only value this parameter accepts is GENERIC_ALL.

### `Name` [in, optional]

Type: **LPCWSTR**

A **NULL**-terminated **UNICODE** string that contains the name to associate with the shared heap.
The name is limited to MAX_PATH characters.
Name comparison is case-sensitive.

If *Name* matches the name of an existing resource, **CreateSharedHandle** fails with [DXGI_ERROR_NAME_ALREADY_EXISTS](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).
This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace.
The remainder of the name can contain any character except the backslash character (\\).
For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).
Fast user switching is implemented using Terminal Services sessions.
Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace.
For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

### `pHandle` [out]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives the NT HANDLE value to the resource to share.
You can use this handle in calls to access the resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following values:

* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if one of the parameters is invalid.
* [DXGI_ERROR_NAME_ALREADY_EXISTS](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the supplied name of the resource to share is already associated with another resource.
* E_ACCESSDENIED if the object is being created in a protected namespace.
* E_OUTOFMEMORY if sufficient memory is not available to create the handle.
* Possibly other error codes that are described in the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) topic.

## Remarks

Both heaps and committed resources can be shared. Sharing a committed resource shares the implicit heap along with the committed resource description, such that a compatible resource description can be mapped to the heap from another device.

For Direct3D 11 and Direct3D 12 interop scenarios, a shared fence is opened in DirectX 11 with the [ID3D11Device5::OpenSharedFence](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11device5-opensharedfence) method, and a shared resource is opened with the [ID3D11Device::OpenSharedResource1](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) method.

For Direct3D 12, a shared handle is opened with the [ID3D12Device::OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-opensharedhandle) or the ID3D12Device::OpenSharedHandleByName method.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)