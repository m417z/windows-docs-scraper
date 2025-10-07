# D3DXF\_FILELOADMEMORY structure

Identifies memory data.

## Members

**lpMemory**

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a block of memory to be loaded.

**dSize**

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the block of memory to be loaded, in bytes.

## Remarks

This structure identifies data to be loaded from memory when an application uses the [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfile--createenumobject) method and specifies the D3DXF\_FILELOAD\_FROMMEMORY flag.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9xof.h |

## See also

[D3DX X File Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file-structures)

