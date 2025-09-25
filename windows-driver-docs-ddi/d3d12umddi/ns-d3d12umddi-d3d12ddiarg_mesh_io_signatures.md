## Description

The **D3D12DDIARG_MESH_IO_SIGNATURES** structure describes a set of signatures for a given mesh shader's output primitives and vertices.

## Members

### `pPrimitiveOutputSignature`

An array of signatures; namely, the set of all registers affected by primitives output by the mesh shader.

### `NumPrimitiveOutputSignatureEntries`

Size, in elements, of the **pPrimitiveOutputSignature** array.

### `pVertexOutputSignature`

An array of signatures; namely, the union of all registers affected by vertices output by the mesh shader.

### `NumVertexOutputSignatureEntries`

Size, in elements, of the **pVertexOutputSignature** array.

## Remarks

This information is passed to the driver on creation of a mesh shader.

See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also