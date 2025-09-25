## Description

The **PFND3D11DDI_QUERYDESIREDMODE1** function is reserved for system use.

## Parameters

### `unnamedParam1`

[in] Pointer to a [**PFND3DDDI_ESCAPECB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) function that is a callback to the kernel-mode driver (KMD). UMD can use this pointer to call into their KMD to help inform them of the mode to choose.

### `unnamedParam2`

[in] Kernel-mode adapter handle to pass to **PFND3DDDI_ESCAPECB**

### `unnamedParam3`

[out] Pointer to a [**D3D11_UMD_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_umd_mode) enumeration that specifies the mode that the UMD wants to run in.

## Return value

This function is reserved for system use and the Direct3D runtime shouldn't be expected to call it. When enabled, this function queries the D3D11on12 mode that a D3D11 user-mode driver (UMD) wants to run in.

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information, see [D3D11On12 open source code](https://github.com/microsoft/D3D11On12).

## See also

[**D3D11_UMD_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_umd_mode)

[**PFND3DDDI_ESCAPECB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)