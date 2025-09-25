## Description

Creates an object that represents a session for content protection. You can then provide that session when you're creating resource or heap objects, to indicate that they should be protected.

> [!NOTE]
> Memory contents can't be transferred from a protected resource to an unprotected resource.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_PROTECTED_RESOURCE_SESSION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_protected_resource_session_desc)\***

A pointer to a constant **D3D12_PROTECTED_RESOURCE_SESSION_DESC** structure, describing the session to create.

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) interface.

### `ppSession` [out]

Type: **void\*\***

A pointer to a memory block that receives an [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) interface pointer to the created session object.

## Return value

## Remarks

## See also