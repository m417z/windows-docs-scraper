# ID3D11Device::CreatePixelShader

## Description

Create a pixel shader.

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled shader.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled pixel shader.

### `pClassLinkage` [in, optional]

Type: **[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)***

A pointer to a class linkage interface (see [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)); the value can be **NULL**.

### `ppPixelShader` [out, optional]

Type: **[ID3D11PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11pixelshader)****

Address of a pointer to a [ID3D11PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11pixelshader) interface. If this is **NULL**, all other parameters will be validated, and if all parameters pass validation this API will return S_FALSE instead of S_OK.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

After creating the pixel shader, you can set it to the device using [ID3D11DeviceContext::PSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetshader).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)