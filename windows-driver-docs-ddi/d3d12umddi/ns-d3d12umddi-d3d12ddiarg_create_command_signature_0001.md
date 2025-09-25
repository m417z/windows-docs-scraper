# D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 structure

## Description

Describes the parameters that the display driver uses to create a command signature.

## Members

### `ByteStride`

Specifies the size of each argument of a command signature, in bytes.

### `NumArgumentDescs`

Specifies the number of arguments in the command signature.

### `pArgumentDescs`

An array of [**D3D12DDI_INDIRECT_ARGUMENT_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_indirect_argument_desc) structures, containing details of the arguments, including whether the argument is a vertex buffer, constant, constant buffer view, shader resource view, or unordered access view.

### `hRootSignature`

Handle to the root signature.

### `NodeMask`

The set of nodes. For single GPU operation, set this to zero. If there are multiple GPU nodes, set bits to identify the nodes (the device's physical adapters) for which the command signature is to apply. Each bit in the mask corresponds to a single node. Refer to Multi-adapter systems.

## Remarks

Use this structure with [**PFND3D12DDI_CREATE_COMMAND_SIGNATURE_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_command_signature_0001).

See the [Mesh Shader specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also

[**D3D12DDI_INDIRECT_ARGUMENT_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_indirect_argument_desc)

[**PFND3D12DDI_CREATE_COMMAND_SIGNATURE_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_command_signature_0001)