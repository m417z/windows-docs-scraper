# ID3D10Device::CreateInputLayout

## Description

Create an input-layout object to describe the input-buffer data for the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

## Parameters

### `pInputElementDescs` [in]

Type: **const [D3D10_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_input_element_desc)***

An array of the input-assembler stage input data types; each type is described by an element description (see [D3D10_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_input_element_desc)).

### `NumElements` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of input-data types in the array of input-elements.

### `pShaderBytecodeWithInputSignature` [in]

Type: **const void***

A pointer to the compiled shader. To get this pointer see [Getting a Pointer to a Compiled Shader](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-using-shaders-10). The compiled shader code contains a [input signature](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-signatures) which is validated against the array of elements. See remarks.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled shader.

### `ppInputLayout` [out]

Type: **[ID3D10InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)****

A pointer to the input-layout object created (see [ID3D10InputLayout Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)). To validate the other input parameters, set this pointer to be **NULL** and verify that the method returns S_FALSE.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return code is S_OK. See [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues) for failing error codes.

## Remarks

After creating an input layout object, it must be bound to the input-assembler stage before calling a draw API. See [Getting Started with the Input-Assembler Stage (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) for example code.

Once an input-layout object is created from a shader signature, the input-layout object can be reused with any other shader that has an identical input signature (semantics included). This can simplify the creation of input-layout objects when you are working with many shaders with identical inputs.

If a data type in the input-layout declaration does not match the data type in a shader-input signature, CreateInputLayout will generate a warning during compilation. The warning is simply to call attention to the fact that the data may be reinterpreted when read from a register. You may either disregard this warning (if reinterpretation is intentional) or make the data types match in both declarations to eliminate the warning. The [Data Conversion Rules](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-data-conversion) overview describes the rules applied for data type conversion.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>Mapping the vertex data to the shader inputs with an input layout is a new way of doing things in Direct3D 10 that improves performance.<br><br>In Direct3D 10 the vertex data is mapped to the shader inputs when the input layout object is created, whereas in Direct3D 9 this mapping was done at Draw time based on the currently bound vertex declarations, vertex buffers, and vertex shaders. Doing this mapping when the input layout object is created reduces or eliminates extra linkage work for drivers at Draw time because this re-mapping is no longer necessary. |

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)