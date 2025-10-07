# D3DXFileCreate function

Creates an instance of an [**ID3DXFile**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile) object.

## Parameters

*lplpDirectXFile*

Type: **[**ID3DXFile**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile)\*\***

Address of a pointer to an [**ID3DXFile**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile) interface, representing the created .x file object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: E\_POINTER, E\_OUTOFMEMORY.

## Remarks

After using this function, use [**RegisterTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--registertemplates) or [**RegisterEnumTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--registerenumtemplates) to register templates, [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createenumobject) to create an enumerator object, or [**CreateSaveObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createsaveobject) to create a save object.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3DX9Xof.h |
| Library<br> | D3dx9.lib |

## See also

[D3DX X File Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file-functions)

[**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createenumobject)

[**CreateSaveObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createsaveobject)

[**RegisterEnumTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--registerenumtemplates)

[**RegisterTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--registertemplates)

