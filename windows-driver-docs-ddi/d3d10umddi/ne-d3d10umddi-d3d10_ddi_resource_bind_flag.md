# D3D10_DDI_RESOURCE_BIND_FLAG enumeration

## Description

Identifies how a resource is bound.

## Constants

### `D3D10_DDI_BIND_VERTEX_BUFFER`

The resource can be bound as a vertex buffer in a call to the driver's [IaSetVertexBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setvertexbuffers) function.

### `D3D10_DDI_BIND_INDEX_BUFFER`

The resource can be bound as an index buffer in a call to the driver's [IaSetIndexBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setindexbuffer) function.

### `D3D10_DDI_BIND_CONSTANT_BUFFER`

 The resource can be bound as a constant buffer.

### `D3D10_DDI_BIND_SHADER_RESOURCE`

The resource can be bound as a shader resource in a call to the [GsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources), [PsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources), or [VsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `D3D10_DDI_BIND_STREAM_OUTPUT`

The resource can be bound as a stream output.

### `D3D10_DDI_BIND_RENDER_TARGET`

The resource can be bound as a render target.

### `D3D10_DDI_BIND_DEPTH_STENCIL`

 The resource can be bound as a depth-stencil buffer.

### `D3D10_DDI_BIND_PIPELINE_MASK`

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the first seven values from this enumeration.

### `D3D10_DDI_BIND_PRESENT`

The resource can be used in a call to the [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function (that is, the resource can be used as a back buffer).

### `D3D10_DDI_BIND_MASK`

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the Direct3D version 10 values from this enumeration.

### `D3D11_DDI_BIND_UNORDERED_ACCESS`

The resource can be bound as an unordered-access buffer.

Supported starting with Windows 8.

The resource can be bound as an unordered-access buffer.

Supported starting with Windows 7.

### `D3D11_DDI_BIND_DECODER`

The resource is a two-dimensional (2-D) texture that is filled by the video decoder engine.

This value cannot be used simultaneously with the **D3D10_DDI_BIND_RENDER_TARGET** enumeration value.

Supported starting with Windows 8.

### `D3D11_DDI_BIND_VIDEO_ENCODER`

The resource is used as an input for a hardware-encode Media Foundation Transform (MFT).

This value cannot be used simultaneously with these values from this enumeration:

* **D3D11_DDI_BIND_CONSTANT_BUFFER**
* **D3D11_DDI_BIND_DEPTH_STENCIL**
* **D3D11_DDI_BIND_INDEX_BUFFER**
* **D3D11_DDI_BIND_VERTEX_BUFFER**

Supported starting with Windows 8.

### `D3D11_DDI_BIND_CAPTURE`

The 2-D texture is used to receive data from the capture interface.

This value cannot be used simultaneously with these values from this enumeration:

* **D3D11_DDI_BIND_CONSTANT_BUFFER**
* **D3D11_DDI_BIND_DECODER**
* **D3D11_DDI_BIND_DEPTH_STENCIL**
* **D3D11_DDI_BIND_INDEX_BUFFER**
* **D3D11_DDI_BIND_RENDER_TARGET**
* **D3D11_DDI_BIND_STREAM_OUTPUT**
* **D3D11_DDI_BIND_UNORDERED_ACCESS**
* **D3D11_DDI_BIND_VERTEX_BUFFER**

Supported starting with Windows 8.

### `D3D11_DDI_BIND_PIPELINE_MASK`

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the first nine values from this enumeration.

Supported starting with Windows 8.

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the first nine values from this enumeration.

Supported starting with Windows 7.

### `D3D11_DDI_BIND_MASK`

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the Direct3D version 11 and version 10 values from this enumeration.

Supported starting with Windows 8.

A mask value that indicates the valid bitfields in a bitwise **OR** combination of the Direct3D version 11 and version 10 values from this enumeration.

Supported starting with Windows 7.

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[GsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources)

[IaSetIndexBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setindexbuffer)

[IaSetVertexBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setvertexbuffers)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[PsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources)

[VsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources)