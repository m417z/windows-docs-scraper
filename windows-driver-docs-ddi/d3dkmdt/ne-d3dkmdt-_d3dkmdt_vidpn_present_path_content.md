# _D3DKMDT_VIDPN_PRESENT_PATH_CONTENT enumeration

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_CONTENT enumeration is used to indicate the type of content that is displayed on a VidPN present path.

## Constants

### `D3DKMDT_VPPC_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_PRESENT_PATH_CONTENT has not yet been assigned a meaningful value.

### `D3DKMDT_VPPC_GRAPHICS`

Indicates that the path displays graphics content.

### `D3DKMDT_VPPC_VIDEO`

Indicates that the path displays video content.

### `D3DKMDT_VPPC_NOTSPECIFIED`

Indicates that no content type has been specified.

## Remarks

The **Content** member of a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a value from the D3DKMDT_VIDPN_PRESENT_PATH_CONTENT enumeration.