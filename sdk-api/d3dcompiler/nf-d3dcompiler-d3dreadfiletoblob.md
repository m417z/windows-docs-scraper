# D3DReadFileToBlob function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store.

Reads a file that is on disk into memory.

## Parameters

### `pFileName` [in]

A pointer to a constant null-terminated string that contains the name of the file to read into memory.

### `ppContents` [out]

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that contains information that **D3DReadFileToBlob** read from the *pFileName* file. You can use this **ID3DBlob** interface to access the file information and pass it to other compiler functions.

## Return value

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DReadFileToBlob** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)