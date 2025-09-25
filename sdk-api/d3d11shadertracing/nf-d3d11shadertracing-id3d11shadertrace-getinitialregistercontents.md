# ID3D11ShaderTrace::GetInitialRegisterContents

## Description

Retrieves the initial contents of the specified input register.

## Parameters

### `pRegister` [in]

A pointer to a [D3D11_TRACE_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_register) structure that describes the input register to retrieve the initial contents from. You can retrieve valid initial data from only the following input register types. That is, to retrieve valid data, the **RegType** member of **D3D11_TRACE_REGISTER** must be one of the following values:

* D3D11_TRACE_INPUT_REGISTER
* D3D11_TRACE_INPUT_PRIMITIVE_ID_REGISTER
* D3D11_TRACE_IMMEDIATE_CONSTANT_BUFFER

Valid data is indicated by the **ValidMask** member of the [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value) structure that *pValue* points to.

### `pValue` [out]

A pointer to a [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value) structure. **GetInitialRegisterContents** fills the members of this structure with information about the initial contents.

## Return value

**GetInitialRegisterContents** returns:

* **S_OK** if the method retrieves the initial register contents.
* **E_FAIL** if a trace is not available.
* **E_INVALIDARG** if *pRegister* is invalid or NULL or if *pValue* is NULL.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

You can call **GetInitialRegisterContents** for registers other than the input register types that are specified in the *pRegister* parameter description. However, **GetInitialRegisterContents** sets the **ValidMask** member of the [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value) structure to which *pValue* points to empty (all zeros, 0000), and the register values that the **Bits** member of **D3D11_TRACE_VALUE** specifies are meaningless. The data that **GetInitialRegisterContents** returns is not affected by stepping in a trace; however, the data that is returned is affected by changing the stamp index through a call to [ID3D11ShaderTrace::PSSelectStamp](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-psselectstamp).

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)