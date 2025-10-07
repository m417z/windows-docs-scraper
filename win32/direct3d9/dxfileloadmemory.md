# DXFILELOADMEMORY structure

Identifies memory data. Deprecated.

## Members

**lpMemory**

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a block of memory to be loaded.

**dSize**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the block of memory to be loaded, in bytes.

## Remarks

This structure identifies a resource to be loaded when an application uses the [**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject) method and specifies DXFILELOAD\_FROMMEMORY.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | DXFile.h |

## See also

[X File Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-x-file-structures)

[**CreateEnumObject**](https://learn.microsoft.com/windows/win32/direct3d9/idirectxfile--createenumobject)

[DXFILE Constants](https://learn.microsoft.com/windows/win32/direct3d9/dxfile)

