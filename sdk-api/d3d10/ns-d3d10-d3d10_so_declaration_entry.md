# D3D10_SO_DECLARATION_ENTRY structure

## Description

Description of a vertex element in a vertex buffer in an output slot.

## Members

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of output element. Possible values: "POSITION", "NORMAL", or "TEXCOORD0".

### `SemanticIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Output element's zero-based index. Should be used if, for example, you have more than one texture coordinate stored in each vertex.

### `StartComponent`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Which component of the entry to begin writing out to. Valid values are 0 ~ 3. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.

### `ComponentCount`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of components of the entry to write out to. Valid values are 1 ~ 4. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.

### `OutputSlot`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The output slot that contains the vertex buffer that contains this output entry.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)