# D3D10_SHADER_DEBUG_FILE_INFO structure

## Description

Describes files included by a shader.

## Members

### `FileName`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to the LPCSTR for the file name.

### `FileNameLen`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the file name.

### `FileData`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to the file data.

### `FileLen`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the file.

## Remarks

The **D3D10_SHADER_DEBUG_FILE_INFO** structure is used with the [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info) structure.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)