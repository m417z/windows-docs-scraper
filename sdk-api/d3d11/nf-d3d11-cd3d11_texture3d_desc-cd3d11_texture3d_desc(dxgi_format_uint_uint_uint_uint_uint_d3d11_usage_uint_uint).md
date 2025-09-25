# CD3D11_TEXTURE3D_DESC::CD3D11_TEXTURE3D_DESC(DXGI_FORMAT,UINT,UINT,UINT,UINT,UINT,D3D11_USAGE,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_TEXTURE3D_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151706(v=vs.85)) structure that is initialized with [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc) values.

## Parameters

### `format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the texture format.

### `width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture width (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device.

### `height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture height (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device.

### `depth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture depth (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device.

### `mipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels in the texture. See the remarks in [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.

### `bindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)-typed values that are combined by using a bitwise OR operation. The resulting value specifies how to bind the texture to pipeline stages.

### `usage`

Type: **[D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)**

A [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)-typed value that identifies how the texture is to be read from and written to.

### `cpuaccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag)-typed values that are combined by using a bitwise OR operation. The resulting value specifies the types of CPU access allowed.

### `miscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag)-typed values that are combined by using a bitwise OR operation. The resulting value identifies other, less common resource options.

## See also

[CD3D11_TEXTURE3D_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151706(v=vs.85))