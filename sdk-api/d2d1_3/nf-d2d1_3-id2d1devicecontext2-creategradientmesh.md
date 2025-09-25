# ID2D1DeviceContext2::CreateGradientMesh

## Description

Creates a new [ID2D1GradientMesh](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1gradientmesh) instance using the given array of patches.

## Parameters

### `patches` [in]

Type: **const [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch)***

A pointer to the array containing the patches to be used in this mesh.

### `patchesCount`

Type: **UINT32**

The number of patches in the patches argument to read.

### `gradientMesh` [out]

Type: **[ID2D1GradientMesh](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1gradientmesh)****

When this method returns, contains the address of a pointer to the new gradient mesh.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)