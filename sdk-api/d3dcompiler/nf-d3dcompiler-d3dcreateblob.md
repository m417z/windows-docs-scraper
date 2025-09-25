# D3DCreateBlob function

## Description

Creates a buffer.

## Parameters

### `Size` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes in the blob.

### `ppBlob` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

The address of a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that is used to retrieve the buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The latest D3dcompiler_nn.dll contains the **D3DCreateBlob** compiler function. Therefore, you are no longer required to create and use an arbitrary length data buffer by using the [D3D10CreateBlob](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createblob) function that is contained in D3d10.dll.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)