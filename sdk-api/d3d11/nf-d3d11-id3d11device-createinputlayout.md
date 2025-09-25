# ID3D11Device::CreateInputLayout

## Description

Create an input-layout object to describe the input-buffer data for the input-assembler stage.

## Parameters

### `pInputElementDescs` [in]

Type: **const [D3D11_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_input_element_desc)***

An array of the input-assembler stage input data types; each type is described by an element description (see [D3D11_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_input_element_desc)).

### `NumElements` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of input-data types in the array of input-elements.

### `pShaderBytecodeWithInputSignature` [in]

Type: **const void***

A pointer to the compiled shader. The compiled shader code contains a input signature which is validated against the array of elements. See remarks.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled shader.

### `ppInputLayout` [out, optional]

Type: **[ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)****

A pointer to the input-layout object created (see [ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)). To validate the other input parameters, set this pointer to be **NULL** and verify that the method returns S_FALSE.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return code is S_OK. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for failing error codes.

## Remarks

After creating an input layout object, it must be bound to the input-assembler stage before calling a draw API.

Once an input-layout object is created from a shader signature, the input-layout object can be reused with any other shader that has an identical input signature (semantics included). This can simplify the creation of input-layout objects when you are working with many shaders with identical inputs.

If a data type in the input-layout declaration does not match the data type in a shader-input signature, CreateInputLayout will generate a warning during compilation. The warning is simply to call attention to the fact that the data may be reinterpreted when read from a register. You may either disregard this warning (if reinterpretation is intentional) or make the data types match in both declarations to eliminate the warning.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)