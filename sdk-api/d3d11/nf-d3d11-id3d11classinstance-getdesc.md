# ID3D11ClassInstance::GetDesc

## Description

Gets a description of the current HLSL class.

## Parameters

### `pDesc` [out]

Type: **[D3D11_CLASS_INSTANCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_class_instance_desc)***

A pointer to a [D3D11_CLASS_INSTANCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_class_instance_desc) structure that describes the current HLSL class.

## Remarks

For more information about using the [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance) interface, see
[Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

An instance is not restricted to being used for a single type in a single shader. An instance is flexible and can be used for any shader that used the same type name or instance name when the instance was generated.

* A created instance will work for any shader that contains a type of the same type name.
  For instance, a class instance created with the type name **DefaultShader** would work in any shader that contained a type **DefaultShader** even though several shaders could describe a different type.
* A gotten instance maps directly to an instance name/index in a shader.
  A class instance acquired using GetClassInstance will work for any shader that contains a class instance of the name used to generate the runtime instance, the instance does not have to be the same type in all of the shaders it's used in.

An instance does not replace the importance of reflection for a particular shader since a gotten instance will not know its slot location and a created instance only specifies a type name.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)