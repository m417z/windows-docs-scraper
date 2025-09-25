# DXGKDDI_ESCAPE callback function

## Description

The *DxgkDdiEscape* function shares information with the user-mode display driver.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pEscape` [in]

A pointer to a [DXGKARG_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape) structure that contains information about the shared information.

**Note** In order for the **DxgkDdiEscape** call to be made under the second level, the **HardwareAccess** flag must be set within the [D3DDDI_ESCAPEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags) structure that is a member of *DXGKARG_ESCAPE*. If this flag is not set, then the call will fail.

## Return value

*DxgkDdiEscape* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiEscape successfully shared information.|
|STATUS_INVALID_PARAMETER|Parameters that were passed to DxgkDdiEscape contained errors that prevented it from completing.|
|STATUS_NO_MEMORY|DxgkDdiEscape could not allocate memory that was required for it to complete.|
|STATUS_PRIVILEGED_INSTRUCTION|DxgkDdiEscape detected nonprivileged instructions (that is, instructions that access memory beyond the privilege of the current central processing unit [CPU] process).|
|STATUS_ILLEGAL_INSTRUCTION|DxgkDdiEscape detected instructions that graphics hardware could not support.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiEscape.|

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiEscape* function whenever the user-mode display driver must share information with the display miniport driver in a way that is not supported through other driver communications.

*DxgkDdiEscape* should be made pageable.

## See also

[DXGKARG_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)