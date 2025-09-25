## Description

Creation arguments for a protected resource session.

## Members

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the crypto session applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `ProtectionType`

The GUID that represents the protection type. Microsoft defines D3D12DDI_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED. This DDI and corresponding API may be extended by IHV's, but requires Microsoft approval. Allowed GUIDs are controlled by an allow list. Developer mode disables the check to allow for private IHV development.

## Remarks

See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also

[**PFND3D12DDI_CALCPRIVATEPROTECTEDRESOURCESESSIONSIZE_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivateprotectedresourcesessionsize_0074)

[**PFND3D12DDI_CREATEPROTECTEDRESOURCESESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createprotectedresourcesession_0074)