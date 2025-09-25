# D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION structure

## Description

Associates a subobject defined directly in a state object with shader exports.

## Members

### `pSubobjectToAssociate`

Pointer to the subobject in current state object to define an association to.

### `NumExports`

Size of the *pExports* array. If 0, this is being explicitly defined as a default association. Another way to define a default association is to omit this subobject association for that subobject completely.

### `pExports`

The array of exports with which the subobject is associated.

## Remarks

Depending on the flags specified in the optional [D3D12_STATE_OBJECT_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_state_object_config) subobject for opting into cross linkage, the exports being associated don’t necessarily have to be present in the current state object, or one that has been seen yet, to be resolved later, on raytracing pipeline state object (RTPSO) creation for example.