## Description

Protected resource session types data.

## Members

### `NodeIndex` [in]

In multi-adapter operation, **NodeIndex** indicates which physical adapter of the device this operation applies to.

### `Count` [in]

Size of the **pTypes** array. This value must match the count returned through the D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT check.

### `pTypes` [out]

On return, this array is populated with the supported protected resource session types.

## Remarks

See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also