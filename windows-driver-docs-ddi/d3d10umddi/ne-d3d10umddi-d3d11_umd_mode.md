## Description

The **D3D11_UMD_MODE** enumeration specifies the mode that a native D3D11 user-mode driver wants to run in.

## Constants

### `D3D11_UMD_MODE_NATIVE11`

Use the IHV's native D3D11 UMD without enlightment.

### `D3D11_UMD_MODE_SYSTEM11ON12`

Use the version of 11on12 that ships with the operating system.

### `D3D11_UMD_MODE_VENDOR11ON12`

Use the IHV's native D3D11 UMD with 11on12 enlightment.

## Remarks

For more information, see [D3D11On12 open source code](https://github.com/microsoft/D3D11On12).

## See also

[**PFND3D11DDI_QUERYDESIREDMODE1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_querydesiredmode1)