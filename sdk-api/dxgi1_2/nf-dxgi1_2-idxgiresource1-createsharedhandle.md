# IDXGIResource1::CreateSharedHandle

## Description

Creates a handle to a shared resource. You can then use the returned handle with multiple Direct3D devices.

## Parameters

### `pAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that contains two separate but related data members: an optional security descriptor, and a Boolean
value that determines whether child processes can inherit the returned handle.

Set this parameter to **NULL** if you want child processes that the
application might create to not inherit the handle returned by
**CreateSharedHandle**, and if you want the resource that is associated with the returned handle to get a default security
descriptor.

The **lpSecurityDescriptor** member of the structure specifies a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) for the resource. Set
this member to **NULL** if you want the runtime to assign a default security descriptor to the resource that is associated with the returned handle. The ACLs in the default security descriptor for the resource come from the primary or impersonation token of the creator. For more info, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `dwAccess` [in]

The requested access rights to the resource. In addition to the [generic access rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights), DXGI defines the following values:

* **DXGI_SHARED_RESOURCE_READ** ( 0x80000000L ) - specifies read access to the resource.
* **DXGI_SHARED_RESOURCE_WRITE** ( 1 ) - specifies write access to the resource.

You can combine these values by using a bitwise OR operation.

### `lpName` [in, optional]

The name of the resource to share. The name is limited to MAX_PATH characters. Name comparison is case sensitive.

You will need the resource name if you call the [ID3D11Device1::OpenSharedResourceByName](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresourcebyname) method to access the shared resource by name. If you instead call the [ID3D11Device1::OpenSharedResource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) method to access the shared resource by handle, set this parameter to **NULL**.

If *lpName* matches the name of an existing resource, **CreateSharedHandle** fails with [DXGI_ERROR_NAME_ALREADY_EXISTS](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error). This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

### `pHandle` [out]

A pointer to a variable that receives the NT HANDLE value to the resource to share. You can use this handle in calls to access the resource.

## Return value

Returns S_OK if successful; otherwise, returns one of the following values:

* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if one of the parameters is invalid.
* [DXGI_ERROR_NAME_ALREADY_EXISTS](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the supplied name of the resource to share is already associated with another resource.
* E_ACCESSDENIED if the object is being created in a protected namespace.
* E_OUTOFMEMORY if sufficient memory is not available to create the handle.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **CreateSharedHandle** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

**CreateSharedHandle** only returns the NT handle when you created the resource as shared and specified that it uses NT handles (that is, you set the [D3D11_RESOURCE_MISC_SHARED_NTHANDLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) and [D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flags). If you created the resource as shared and specified that it uses NT handles, you must use **CreateSharedHandle** to get a handle for sharing. In this situation, you can't use the [IDXGIResource::GetSharedHandle](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiresource-getsharedhandle) method because it will fail.

You can pass the handle that **CreateSharedHandle** returns in a call to the [ID3D11Device1::OpenSharedResource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) method to give a device access to a shared resource that you created on a different device.

Because the handle that **CreateSharedHandle** returns is an NT handle, you can use the handle with [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle), [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle), and so on. You can call **CreateSharedHandle** only once for a shared resource; later calls fail. If you need more handles to the same shared resource, call **DuplicateHandle**. When you no longer need the shared resource handle, call **CloseHandle** to close the handle, in order to avoid memory leaks.

If you pass a name for the resource to *lpName* when you call **CreateSharedHandle** to share the resource, you can subsequently pass this name in a call to the [ID3D11Device1::OpenSharedResourceByName](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresourcebyname) method to give another device access to the shared resource. If you use a named resource, a malicious user can use this named resource before you do and prevent your app from starting. To prevent this situation, create a randomly named resource and store the name so that it can only be obtained by an authorized user. Alternatively, you can use a file for this purpose. To limit your app to one instance per user, create a locked file in the user's profile directory.

If you created the resource as shared and did not specify that it uses NT handles, you cannot use **CreateSharedHandle** to get a handle for sharing because **CreateSharedHandle** will fail.

#### Examples

``` syntax
ID3D11Texture2D* pTexture2D;
ID3D11Device* pDevice;

pDevice->CreateTexture2D(…, &pTexture2D); // Create the texture as shared with NT HANDLEs.

HANDLE handle;
IDXGIResource1* pResource;
pTexture2D->QueryInterface(__uuidof(IDXGIResource1), (void**) &pResource);
pResource->CreateSharedHandle(NULL,
         DXGI_SHARED_RESOURCE_READ | DXGI_SHARED_RESOURCE_WRITE,
         NULL,
         &handle);

// Pass the handle to another process to share the resource.

```

## See also

[IDXGIResource1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiresource1)