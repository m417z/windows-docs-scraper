## Description

For a [DisplaySurface](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaysurface) or a [DisplayFence](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displayfence) object, creates a shared handle that can be used for interop with Direct3D or other graphics APIs.

## Parameters

### `pObject`

A pointer to the **IUnknown** interface of a [DisplaySurface](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaysurface) or a [DisplayFence](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displayfence) object.

### `pSecurityAttributes`

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that contains two separate but related data members: an optional security descriptor, and a Boolean value that determines whether child processes can inherit the returned handle.

Set this parameter to `nullptr` if you want child processes that the application might create to not inherit the handle returned by **CreateSharedHandle**, and if you want the resource that is associated with the returned handle to get a default security descriptor.

The *lpSecurityDescriptor* member of the structure specifies a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) for the resource. Set this member to `nullptr` if you want the runtime to assign a default security descriptor to the resource that is associated with the returned handle. The access control lists (ACLs) in the default security descriptor for the resource come from the primary or impersonation token of the creator. For more info, see [Synchronization object security and access rights](https://learn.microsoft.com/windows/win32/sync/synchronization-object-security-and-access-rights).

### `Access`

The requested access rights to the resource. In addition to the [Generic access rights](https://learn.microsoft.com/windows/win32/secauthz/generic-access-rights), a surface can use these values.

- **DXGI_SHARED_RESOURCE_READ** (0x80000000L). Specifies read access to the resource.
- **DXGI_SHARED_RESOURCE_WRITE** (1). Specifies write access to the resource.

You can combine these values by using a bitwise OR operation.

If *pObject* is a fence, then you must use **GENERIC_ALL**.

### `Name`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A null-terminated Unicode string that contains the name to associate with the shared heap. The name is limited to **MAX_PATH** characters. Name comparison is case-sensitive.

If *Name* matches the name of an existing resource, then **CreateSharedHandle** fails with [DXGI_ERROR_NAME_ALREADY_EXISTS](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error). This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (`\`). For more information, see [Kernel object namespaces](https://learn.microsoft.com/windows/win32/termserv/kernel-object-namespaces). Fast user-switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object namespaces](https://learn.microsoft.com/windows/win32/sync/object-namespaces).

### `pHandle`

A pointer to a **HANDLE** that receives that new shared handle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** if it succeeded, otherwise a failure code indicating why it failed. If it succeeded, then *pHandle* will always point to the newly created handle.

## Remarks

The handle returned by **CreateSharedHandle** can be used in any function that requires an "NT handle" to a GPU surface or fence (depending on what object was passed), provided that the caller has been granted access. Here are some examples.

* Share surfaces and fences with Direct3D 12 using [ID3D12Device::OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-opensharedhandle).
* Share surfaces with Direct3D 11 using [ID3D11Device1::OpenSharedResource](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1).
* Share fences with Direct3D 11 using [ID3D11Device5::OpenSharedFence](https://learn.microsoft.com/windows/win32/api/d3d11_4/nf-d3d11_4-id3d11device5-opensharedfence).

Multiple processes can have handles of the same object, enabling use of the object for interprocess synchronization or sharing. The following object-sharing mechanisms are available.

* A child process created by the [CreateProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit a handle to a surface or fence object if the *pSecurityAttributes* parameter of **CreateSharedHandle** enables inheritance.
* A process can specify the object handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle) function to create a duplicate handle that can be used by another process.
* A process can specify the name of the object in a call to the [OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/windows.devices.display.core.interop/nf-windows-devices-display-core-interop-idisplaydeviceinterop-opensharedhandle) or [ID3D12Device::OpenSharedHandleByName](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-opensharedhandlebyname) function.

Use the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The object is destroyed when its last handle has been closed and its last interface reference has been released.

## See also