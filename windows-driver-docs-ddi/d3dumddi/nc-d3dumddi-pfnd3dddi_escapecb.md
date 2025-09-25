# PFND3DDDI_ESCAPECB callback function

## Description

The **pfnEscapeCb** callback function shares information with the display miniport driver.

## Parameters

### `hAdapter`

A handle to the graphics adapter object.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_escape) structure that describes the shared information.

## Return value

**pfnEscapeCb** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | Information was successfully shared. |
| **E_OUTOFMEMORY** | pfnEscapeCb could not complete because of insufficient memory. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect.|
| **D3DDDIERR_DEVICEREMOVED** | pfnEscapeCb could not initiate a call to the display miniport driver's [DxgkDdiEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) function because a Plug and Play (PnP) stop or a Timeout Detection and Recovery (TDR) event occurred. The user-mode display driver function that called pfnEscapeCb must return this error code back to the Direct3D runtime.<br>**Direct3D Version 9** Note: For more information about returning error codes, see [Returning Error Codes Received from Runtime Functions](https://learn.microsoft.com/windows-hardware/drivers/display/returning-error-codes-received-from-runtime-functions).<br>**Direct3D Versions 10 and 11** Note: If the driver function does not return a value (that is, has VOID for a return parameter type), the driver function calls the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function to send an error code back to the runtime. For more information about handling error codes, see [Handling Errors](https://learn.microsoft.com/windows-hardware/drivers/display/handling-errors). |

This function might also return other HRESULT values.

## Remarks

A user-mode display driver calls **pfnEscapeCb** to share miscellaneous information with the display miniport driver in a way that is not supported by any other driver communication. The user-mode display driver can send miscellaneous information to the display miniport driver or can retrieve information from the display miniport driver.

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnEscapeCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

## See also

[D3DDDICB_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_escape)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[DxgkDdiEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)