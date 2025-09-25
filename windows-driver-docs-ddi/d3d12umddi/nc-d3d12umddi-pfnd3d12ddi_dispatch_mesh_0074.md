# PFND3D12DDI_DISPATCH_MESH_0074 callback function

## Description

**PFND3D12DDI_DISPATCH_MESH_0074** launches the thread groups for the amplification shader, or for the mesh shader in a case where no amplification shader is attached.

## Parameters

### `unnamedParam1`

A handle to the command list.

### `unnamedParam2`

Thread group count in X direction.

### `unnamedParam3`

Thread group count in Y direction.

### `unnamedParam4`

Thread group count in Z direction.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DISPATCH_MESH_0074 Pfnd3d12ddiDispatchMesh0074;

// Definition

VOID Pfnd3d12ddiDispatchMesh0074
(
    D3D12DDI_HCOMMANDLIST,
    UINT,
    UINT,
    UINT
)
{...}

```

## Remarks

See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also