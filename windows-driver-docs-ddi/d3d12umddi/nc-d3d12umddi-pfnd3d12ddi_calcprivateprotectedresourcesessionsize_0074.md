# PFND3D12DDI_CALCPRIVATEPROTECTEDRESOURCESESSIONSIZE_0074 callback function

## Description

Used to calculate the size of a protected resource session.

## Parameters

### `hDrvDevice`

Handle to the hardware device being processed.

### `pArgs`

Pointer to a [**D3D12DDIARG_CREATE_PROTECTED_RESOURCE_SESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_protected_resource_session_0074) structure with the arguments used to open a protected resource session.

## Return value

Returns the size of the session in bytes.

## Remarks

The D3D runtime allocates memory for storing the driver's CPU object representing the protected resource session. This method is used to calculate the driver object size.

See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also

[**D3D12DDIARG_CREATE_PROTECTED_RESOURCE_SESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_protected_resource_session_0074)

[**PFND3D12DDI_CREATEPROTECTEDRESOURCESESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createprotectedresourcesession_0074)