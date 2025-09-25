# PFND3D12DDI_CREATEPROTECTEDRESOURCESESSION_0074 callback function

## Description

Used to create a protected resource session.

## Parameters

### `hDrvDevice`

Handle to the hardware device being processed.

### `pArgs`

Pointer to a [**D3D12DDIARG_CREATE_PROTECTED_RESOURCE_SESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_protected_resource_session_0074) structure containing the arguments used to create a protected resource session.

### `hDrvProtectedResourceSession`

Handle for driver to place its object representing the protected resource session.

### `hRtProtectedSession`

Handle used to call [**PFND3D12DDI_CREATE_PROTECTED_SESSION_CB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_protected_session_cb_0030) during protected session resource creation.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## Remarks

The D3D runtime allocates memory for storing the driver's CPU object representing the protected resource session. This callback creates the protected resource session.

See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also

[**D3D12DDIARG_CREATE_PROTECTED_RESOURCE_SESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_protected_resource_session_0074)

[**PFND3D12DDI_CREATE_PROTECTED_SESSION_CB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_protected_session_cb_0030)