# D3D12_STATE_OBJECT_FLAGS enumeration

## Description

Specifies constraints for state objects. Use values from this enumeration in the [D3D12_STATE_OBJECT_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_state_object_config) structure.

## Constants

### `D3D12_STATE_OBJECT_FLAG_NONE:0`

No state object constraints.

### `D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS:0x1`

This flag applies to state objects of type collection only. Otherwise this flag is ignored.

The exports from this collection are allowed to have unresolved references (dependencies) that would have to be resolved (defined) when the collection is included in a containing state object, such as a raytracing pipeline state object (RTPSO). This includes depending on externally defined subobject associations to associate an external subobject (e.g. root signature) to a local export.

In the absence of this flag, all exports in this collection must have their dependencies fully locally resolved, including any necessary subobject associations being defined locally. Advanced implementations/drivers will have enough information to compile the code in the collection and not need to keep around any uncompiled code (unless the **D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS** flag is set), so that when the collection is used in a containing state object (e.g. RTPSO), minimal work needs to be done by the driver, ideally a “cheap” link at most.

### `D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS:0x2`

This flag applies to state objects of type collection only. Otherwise this flag is ignored.

If this collection is included in another state object (e.g. RTPSO), shaders / functions in the rest of the containing state object are allowed to depend on (e.g. call) exports from this collection.

In the absence of this flag (default), exports from this collection cannot be directly referenced by other parts of containing state objects (e.g. RTPSO). This can reduce memory footprint for the collection slightly since drivers don’t need to keep uncompiled code in the collection on the off chance that it may get called by some external function that would then compile all the code together. That said, if not all necessary subobject associations have been locally defined for code in this collection, the driver may not be able to compile shader code yet and may still need to keep uncompiled code around.

A subobject association defined externally that associates an external subobject to a local export does not count as an external dependency on a local definition, so the presence or absence of this flag does not affect whether the association is allowed or not. On the other hand if the current collection defines a subobject association for a locally defined subobject to an external export (e.g. shader), that counts as an external dependency on a local definition and this flag must be set.

Regardless of the presence or absence of this flag, shader entrypoints (such as hit groups or miss shaders) in the collection are visible as entrypoints to a containing state object (e.g. RTPSO) if exported by it. In the case of an RTPSO, the exported entrypoints can be used in shader tables for raytracing.