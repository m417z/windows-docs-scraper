# D3DXF\_FILELOADRESOURCE structure

Identifies resource data.

## Members

**hModule**

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle of the module containing the resource to be loaded. If this member is **NULL**, the resource must be attached to the executable file that will use it.

**lpName**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string specifying the name of the resource to be loaded. For example, if the resource is a mesh, this member should specify the name of the mesh file.

**lpType**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string specifying the user-defined type identifying the resource.

## Remarks

This structure identifies a resource to be loaded when an application uses the [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createenumobject) method and specifies the [D3DXF\_FILELOAD\_FROMRESOURCE](https://learn.microsoft.com/windows/win32/direct3d9/d3dxf) flag.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9xof.h |

## See also

[D3DX X File Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file-structures)

