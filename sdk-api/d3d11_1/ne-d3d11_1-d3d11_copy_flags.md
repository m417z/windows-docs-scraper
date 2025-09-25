# D3D11_COPY_FLAGS enumeration

## Description

**Note** This enumeration is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Specifies how to handle the existing contents of a resource during a copy or update operation of a region within that resource.

## Constants

### `D3D11_COPY_NO_OVERWRITE:0x1`

The existing contents of the resource cannot be overwritten.

### `D3D11_COPY_DISCARD:0x2`

The existing contents of the resource are undefined and can be discarded.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)

[ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1)

[ID3D11DeviceContext1::UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1)