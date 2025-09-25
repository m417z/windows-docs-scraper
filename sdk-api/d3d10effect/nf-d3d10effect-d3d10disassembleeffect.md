# D3D10DisassembleEffect function

## Description

This function -- which disassembles a compiled effect into a text string that contains assembly instructions and register assignments -- has been deprecated. Instead, use [D3DDisassemble10Effect](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3ddisassemble10effect).

## Parameters

### `pEffect` [in]

Type: **[ID3D10Effect](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)***

A pointer to an [ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect), which contains the compiled effect.

### `EnableColorCode` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Include HTML tags in the output to color code the result.

### `ppDisassembly` [out]

Type: **[ID3D10Blob](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)****

A pointer to an [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) which contains the disassembled shader.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This returned text includes a header with the version of the HLSL compiler used to generate this object, comments describing the memory layout of the constant buffers used by the shader, input and output signatures, and resource binding points.

Here is an example of disassembling a compiled effect. The example assumes you start with a compiled effect (shown as *l_pBlob_Effect* which you can see in [Compile an Effect (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-effects-compile)).

```

LPCSTR commentString = NULL;
ID3D10Blob* pIDisassembly = NULL;
char* pDisassembly = NULL;
if( pVSBuf )
{
    D3D10DisassembleEffect( (UINT*) l_pBlob_Effect->GetBufferPointer(),
        l_pBlob_Effect->GetBufferSize(), TRUE, commentString, &pIDisassembly );
    if( pIDisassembly )
    {
        FILE* pFile = fopen( "effect.htm", "w" );
        if( pFile)
        {
            fputs( (char*)pIDisassembly->GetBufferPointer(), pFile );
            fclose( pFile );
        }
    }
}

```

## See also

[Effect Functions (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)