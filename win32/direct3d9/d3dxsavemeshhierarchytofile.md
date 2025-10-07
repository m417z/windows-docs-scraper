# D3DXSaveMeshHierarchyToFile function

Creates a .x file and saves the mesh hierarchy and corresponding animations in it.

## Parameters

*pFilename* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the name of the .x file identifying the saved mesh. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*XFormat* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Format of the .x file (text or binary, compressed or not). See D3DXF\_FILEFORMAT. D3DXF\_FILEFORMAT\_COMPRESSED can be combined (using a logical OR) with either the D3DXF\_FILEFORMAT\_BINARY or D3DXF\_FILEFORMAT\_TEXT flags to reduce the output file size.

*pFrameRoot* \[in\]

Type: **const [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)\***

Root node of the hierarchy to be saved. See [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe).

*pAnimController* \[in\]

Type: **[**LPD3DXANIMATIONCONTROLLER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller)**

Animation controller that has animation sets to be stored. See [**ID3DXAnimationController**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller).

*pUserDataSaver* \[in\]

Type: **[**LPD3DXSAVEUSERDATA**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxsaveuserdata)**

Application-provided interface that allows saving of user data. See [**ID3DXSaveUserData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxsaveuserdata).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: D3DERR\_INVALIDCALL.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXSaveMeshHierarchyToFileW. Otherwise, the function call resolves to D3DXSaveMeshHierarchyToFileA.

This function does not save compressed animation sets.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

[X File Reference](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file)

