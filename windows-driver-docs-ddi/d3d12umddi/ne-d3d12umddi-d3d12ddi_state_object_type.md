# D3D12DDI_STATE_OBJECT_TYPE enumeration

## Description

The **D3D12DDI_STATE_OBJECT_TYPE** enumeration defines the types of state objects that can be created.

## Constants

### `D3D12DDI_STATE_OBJECT_TYPE_COLLECTION`

A collection can contain any amount of subobjects, but doesn’t have constraints. Not all dependencies that the included subobjects have must be resolved in the same collection Even if dependencies are locally defined, the set of subobjects doesn’t have to be the complete set of state that will eventually be used on the GPU. For instance, a collection may not include all shaders needed to *raytrace* a scene, though it could.

The purpose of a collection is to allow an application to pass an arbitrarily large or small collection of state to drivers to compile at once (e.g. on a given thread).

### `D3D12DDI_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE`

An RTPSO (ray tracing pipeline state object) represents a full set of shaders that could be reachable by a DispatchRays() call, with all configuration options resolved, such as local root signatures and other state.

An RTPSO can be thought of as an *executable* state object.

### `D3D12DDI_STATE_OBJECT_TYPE_EXECUTABLE`

This state object type refers to a fully configured and executable pipeline state that can be used for rendering or compute operations.

## Remarks

State objects are used to encapsulate a set of states that configure the graphics pipeline for rendering or compute operations, including those for ray tracing.

State objects have a type that dictates rules about the subobjects they contain and how the state objects can be used.

## See also

[**D3D12DDI_STATE_SUBOBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)