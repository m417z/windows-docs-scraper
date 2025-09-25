# ID3D12StateObjectProperties::GetShaderStackSize

## Description

Gets the amount of stack memory required to invoke a raytracing shader in HLSL.

## Parameters

### `pExportName`

The shader entrypoint in the state object for which to retrieve stack size. For hit groups, an individual shader within the hit group must be specified using the syntax:

hitGroupName::shaderType

Where *hitGroupName* is the entrypoint name for the hit group and *shaderType* is one of:

* intersection
* anyhit
* closesthit

These values are all case-sensitive.

An example value is: "myTreeLeafHitGroup::anyhit".

## Return value

Amount of stack memory, in bytes, required to invoke the shader. If the shader isn’t fully resolved in the state object, or the shader is unknown or of a type for which a stack size isn’t relevant, such as a hit group, the return value is 0xffffffff. The 32-bit 0xffffffff value is used for the UINT64 return value to ensure that bad return values don’t get lost when summed up with other values as part of calculating an overall pipeline stack size.

## Remarks

This method only needs to be called if the app wants to configure the stack size by calling [SetPipelineStackSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12stateobjectproperties-setpipelinestacksize), rather than relying on the conservative default stack size. This method is only valid for ray generation shaders, hit groups, miss shaders, and callable shaders. Even ray generation shaders may return a non-zero value despite being at the bottom of the stack.

For hit groups, stack size must be queried for the individual shaders comprising it (intersection shaders, any hit shaders, closest hit shaders), as each likely has a different stack size requirement. The stack size can’t be queried on these individual shaders directly, as the way they are compiled can be influenced by the overall hit group that contains them. The *pExportName* parameter includes syntax for identifying individual shaders within a hit group.

This API can be called on either collection state objects or raytracing pipeline state objects.

## See also

[ID3D12StateObjectProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobjectproperties)