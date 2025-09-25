# ID2D1GradientMesh::GetPatches

## Description

Returns a subset of the patches that make up this gradient mesh.

## Parameters

### `startIndex`

Type: **UINT32**

Index of the first patch to return.

### `patches`

Type: **[D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch)***

A pointer to the array to be filled with the patch data.

### `patchesCount`

Type: **UINT32**

The number of patches to be returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1GradientMesh](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1gradientmesh)