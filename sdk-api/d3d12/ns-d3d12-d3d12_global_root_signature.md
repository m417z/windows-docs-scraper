# D3D12_GLOBAL_ROOT_SIGNATURE structure

## Description

Defines a global root signature state suboject that will be used with associated shaders.

## Members

### `pGlobalRootSignature`

The root signature that will function as a global root signature. A state object holds a reference to this signature.

## Remarks

The presence of this subobject in a state object is optional. The combination of global and/or local root signatures associated with any given shader function must define all resource bindings declared by the shader with no overlap across global and local root signatures.

If any given function in a call graph is associated with a particular global root signature, any other functions in the graph must either be associated with the same global root signature or none, and the shader entry (the root of the call graph) must be associated with the global root signature.

Different shaders can use different global root signatures (or none) within a state object, however any shaders referenced during a particular [DispatchRays](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-dispatchrays) operation from a command list must have specified the same global root signature as what has been set on the command list as the compute root signature. So it is valid to define a single large state object with multiple global root signatures associated with different subsets of the shaders. Apps are not forced to split their state object just because some shaders use different global root signatures.