# DXFILELOADRESOURCE structure

Identifies resource data. Deprecated.

## Members

**hModule**

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle of the module containing the resource to be loaded. If this member is **NULL**, the resource must be attached to the executable file that will use it.

**lpName**

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string specifying the name of the resource to be loaded. For example, if the resource is a mesh, this member should specify the name of the mesh file.

**lpType**

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string specifying the user-defined type identifying the resource.

## Remarks

This structure identifies a resource to be loaded when an application uses the [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject) method and specifies DXFILELOAD\_FROMRESOURCE.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | DXFile.h |

## See also

[X File Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-x-file-structures)

[**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject)

[DXFILE Constants](https://learn.microsoft.com/windows/win32/direct3d9/dxfile)

