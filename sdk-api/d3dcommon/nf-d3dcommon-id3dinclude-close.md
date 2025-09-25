# ID3DInclude::Close

## Description

A user-implemented method for closing a shader #include file.

## Parameters

### `pData`

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the buffer that contains the include directives. This is the pointer that was returned by the corresponding [ID3DInclude::Open](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-open) call.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The user-implemented **Close** method should return S_OK. If **Close** fails when it closes the #include file, the application programming interface (API) that caused **Close** to be called fails. This failure can occur in one of the following situations:

* The high-level shader language (HLSL) shader fails one of the **D3D10CompileShader***** functions.
* The effect fails one of the **D3D10CreateEffect***** functions.

## Remarks

If [ID3DInclude::Open](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-open) was successful, **Close** is guaranteed to be called before the API using the [ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude) interface returns.

## See also

[ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude)

[ID3DInclude::Open](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-open)