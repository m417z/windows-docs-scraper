# PFND3D12DDI_CREATE_PROTECTED_SESSION_CB_0030 callback function

## Description

Callback to create a graphics kernel protected resource session.

## Parameters

### `hRTDevice`

The hardware device being processed.

### `hRTProtectedSession`

The protected session.

### `pArgs`

Pointer to a [**D3D12DDICB_CREATE_PROTECTED_SESSION_0030**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_create_protected_session_0030) structure containing creation arguments for the protected resource session.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## Remarks

This function is added to the D3D12DDI_CORELAYER_DEVICECALLBACKS function table. This callback must be called during a call to [**PFND3D12DDI_CREATEPROTECTEDRESOURCESESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createprotectedresourcesession_0074).

See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also

[**D3D12DDICB_CREATE_PROTECTED_SESSION_0030**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_create_protected_session_0030)

[**PFND3D12DDI_CREATEPROTECTEDRESOURCESESSION_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createprotectedresourcesession_0074)