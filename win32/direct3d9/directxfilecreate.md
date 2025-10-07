# DirectXFileCreate function

Creates an instance of a DirectXFile object. Deprecated.

## Parameters

*lplpDirectXFile*

Type: **[**LPDIRECTXFILE**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile)\***

Address of a pointer to an [**IDirectXFile**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile) interface, representing the created DirectXFile object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: DXFILEERR\_BADALLOC, DXFILEERR\_BADVALUE.

## Remarks

After using this function, use [**RegisterTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--registertemplates) to register templates, [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject) to create an enumerator object, or [**CreateSaveObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createsaveobject) to create a save object.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | DXFile.h |
| Library<br> | D3dxof.lib |
| DLL<br> | D3dxof.dll |

## See also

[X File Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-x-file-functions)

[**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject)

[**CreateSaveObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createsaveobject)

[**RegisterTemplates**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--registertemplates)

