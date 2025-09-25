# D3D12DDI_EXPORT_SUMMARY_FLAGS enumeration

## Description

Flags indicating properties the runtime has determined about a given shader export, including the graph of functions it may call.

## Constants

### `D3D12DDI_EXPORT_SUMMARY_FLAG_NONE`

No flag.

### `D3D12DDI_EXPORT_SUMMARY_FLAG_UNRESOLVED_RESOURCE_BINDINGS`

Unresolved resource bindings.

### `D3D12DDI_EXPORT_SUMMARY_FLAG_UNRESOLVED_FUNCTIONS`

Unresolved functions.

### `D3D12DDI_EXPORT_SUMMARY_FLAG_UNRESOLVED_ASSOCIATIONS`

Unresolved associations.

## Remarks

Unresolved resource bindings or unresolved functions can only appear for collection state objects, because the runtime ensures all dependencies are resolved for executable state objects.

There is still the possibility of the driver finding code incompatibility while linking code across DXIL (DirectX Intermediate Language) libraries that the runtime missed, since the runtime isn’t doing full linking. For instance, a shader in one DXIL library might call a function where a parameter is a user defined type that has been defined locally. The function being called may appear in a different DXIL library with the same function signature but having the user defined type defined differently there. Without doing full linking, the runtime could miss this, in which case the driver would have to fail state object creation.

## See also