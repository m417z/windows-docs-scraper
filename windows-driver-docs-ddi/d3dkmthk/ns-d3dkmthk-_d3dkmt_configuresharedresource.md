# _D3DKMT_CONFIGURESHAREDRESOURCE structure

## Description

The D3DKMT_CONFIGURESHAREDRESOURCE structure describes parameters that the [D3DKMTConfigureSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconfiguresharedresource) function uses to configure a shared resource.

## Members

### `hDevice` [in]

A handle to the device that the resource is associated with.

### `hResource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the shared resource to configure.

### `IsDwm` [in]

A Boolean value that specifies whether the current process is the Desktop Windows Manager (DWM). **TRUE** indicates DWM; **FALSE** indicates that the current process is non-DWM and is specified by the **hProcess** member.

### `hProcess` [in]

A handle to the process for the non-DWM situation.

### `AllowAccess` [in]

A Boolean value that specifies whether the [D3DKMTConfigureSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconfiguresharedresource) function should allow the process to access the resource. **TRUE** indicates to allow access; **FALSE** indicates to not allow access.

## See also

[D3DKMTConfigureSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconfiguresharedresource)