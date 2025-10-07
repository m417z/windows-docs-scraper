# D3DX10DisassembleShader function

> [!Note]
> Instead of using this legacy function, we recommend that you use the [**D3DDisassemble**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble) API.

This function -- which disassembles a compiled shader into a text string that contains assembly instructions and register assignments -- no longer exists. Instead, use [**D3DDisassemble10Effect**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble10effect).

## Parameters

*pShader* \[in\]

Type: **const void\***

A pointer to the [**compiled shader**](https://learn.microsoft.com/windows/desktop/api/D3D10/nf-d3d10-id3d10device-createinputlayout).

*BytecodeLength* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of pShader.

*EnableColorCode* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Include HTML tags in the output to color code the result.

*pComments* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The comment string at the top of the shader that identifies the shader constants and variables.

*ppDisassembly* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

Address of a buffer (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob)) which contains the disassembled shader.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This returned text includes a header with the version of the HLSL compiler used to generate this object, comments describing the memory layout of the constant buffers used by the shader, input and output signatures, and resource binding points.

Here is an example of disassembling a compiled shader. The example assumes you start with a compiled shader (shown as *pVSBuf* which you can see in [HLSLWithoutFX10 Sample](https://msdn.microsoft.com/library/Ee416414(v=VS.85).aspx)).

```
LPCSTR commentString = NULL;
ID3D10Blob* pIDisassembly = NULL;
char* pDisassembly = NULL;
if( pVSBuf )
{
    D3D10DisassembleShader( (UINT*) pVSBuf->GetBufferPointer(),
        pVSBuf->GetBufferSize(), TRUE, commentString, &pIDisassembly );
    if( pIDisassembly )
    {
        FILE* pFile = fopen( "shader.htm", "w" );
        if( pFile)
        {
            fputs( (char*)pIDisassembly->GetBufferPointer(), pFile );
            fclose( pFile );
        }
    }
}
```

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

