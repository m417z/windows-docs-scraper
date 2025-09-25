## Description

Describes flags for a protected resource session, per adapter.

## Members

### `NodeMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The node mask. For single GPU operation, set this to zero. If there are multiple GPU nodes, then set a bit to identify the node (the device's physical adapter) to which the protected session applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Flags`

Type: **[D3D12_PROTECTED_RESOURCE_SESSION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_protected_resource_session_flags)**

Specifies the supported crypto sessions options.

## Remarks

## See also