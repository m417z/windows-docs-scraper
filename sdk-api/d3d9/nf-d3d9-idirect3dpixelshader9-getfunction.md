# IDirect3DPixelShader9::GetFunction

## Description

Gets a pointer to the shader data.

## Parameters

### `unnamedParam1` [in, out]

Type: **void***

Pointer to a buffer that contains the shader data. The application needs to allocate enough room for this.

### `pSizeOfData` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Size of the data, in bytes. To get the buffer size that is needed to retrieve the data, set pData = **NULL** when calling GetFunction. Then call GetFunction with the returned size, to get the buffer data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be:
D3DERR_INVALIDCALL.

## See also

[IDirect3DPixelShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dpixelshader9)