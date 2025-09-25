# D3DReflectLibrary function

## Description

Creates a library-reflection interface from source data that contains an HLSL library of functions.

**Note** This function is part of the HLSL shader linking technology that you can use on all Direct3D 11 platforms to create precompiled HLSL functions, package them into libraries, and link them into full shaders at run time.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data as an HLSL library of functions.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the block of memory that *pSrcData* points to.

### `riid` [in]

Type: **REFIID**

The reference GUID of the COM interface to use. For example, **IID_ID3D11LibraryReflection**.

### `ppReflector` [out]

Type: **LPVOID***

A pointer to a variable that receives a pointer to a library-reflection interface, [ID3D11LibraryReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11libraryreflection).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)

[ID3D11LibraryReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11libraryreflection)