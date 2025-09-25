# D3D10CreateBlob function

## Description

Create a buffer.

**Note** Instead of using this function, we recommend that you use the [D3DCreateBlob](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcreateblob) API.

## Parameters

### `NumBytes` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes in the blob.

### `ppBuffer` [out]

Type: **[LPD3D10BLOB](https://msdn.microsoft.com/d180fee0-1a69-4250-a0c4-d6e3754f063a)***

The address of a pointer to the buffer (see [ID3D10Blob Interface](https://msdn.microsoft.com/d180fee0-1a69-4250-a0c4-d6e3754f063a)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)