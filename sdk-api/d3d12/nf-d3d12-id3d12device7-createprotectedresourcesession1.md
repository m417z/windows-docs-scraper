## Description

**CreateProtectedResourceSession1** revises the [**ID3D12Device4::CreateProtectedResourceSession**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession) method with provision (in the structure passed via the *pDesc* parameter) for a globally unique identifier (**GUID**) that indicates the type of protected resource session.

Calling **ID3D12Device4::CreateProtectedResourceSession** is equivalent to calling **ID3D12Device7::CreateProtectedResourceSession1** with the **D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED** GUID.

## Parameters

### `pDesc`

Type: \_In\_ **const [D3D12_PROTECTED_RESOURCE_SESSION_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_protected_resource_session_desc1)\***

A pointer to a constant **D3D12_PROTECTED_RESOURCE_SESSION_DESC1** structure, describing the session to create.

### `riid`

Type: \_In\_ **REFIID**

The GUID of the interface to a protected session. Most commonly, [ID3D12ProtectedResourceSession1](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession1), although it may be any **GUID** for any interface. If the protected session object doesn't support the interface for this **GUID**, the getter will return **E_NOINTERFACE**.

### `ppSession`

Type: \_COM\_Outptr\_ **void\*\***

A pointer to a memory block that receives a pointer to the session for the given protected session (the specific interface type returned depends on *riid*).

## Return value

## Remarks

## See also