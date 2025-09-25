## Description

Describes flags and protection type for a protected resource session, per adapter.

## Members

### `NodeMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The node mask. For single GPU operation, set this to zero. If there are multiple GPU nodes, then set a bit to identify the node (the device's physical adapter) to which the protected session applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Flags`

Type: **[D3D12_PROTECTED_RESOURCE_SESSION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_protected_resource_session_flags)**

Specifies the supported crypto sessions options.

### `ProtectionType`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The GUID that represents the protection type. Microsoft defines **D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED**.

Using the **D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED** GUID is equivalent to calling [**ID3D12Device4::CreateProtectedResourceSession**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

## Remarks

## See also