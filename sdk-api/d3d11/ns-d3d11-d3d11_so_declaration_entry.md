# D3D11_SO_DECLARATION_ENTRY structure

## Description

Description of a vertex element in a vertex buffer in an output slot.

## Members

### `Stream`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based, stream number.

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of output element; possible values include: **"POSITION"**, **"NORMAL"**, or **"TEXCOORD0"**.
Note that if *SemanticName* is **NULL** then
*ComponentCount* can be greater than 4 and the described entry will be a gap in the stream out where no data will be written.

### `SemanticIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Output element's zero-based index. Should be used if, for example, you have more than one texture coordinate stored in each vertex.

### `StartComponent`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Which component of the entry to begin writing out to. Valid values are 0 to 3. For example, if you only wish to output to the y and z components
of a position, then StartComponent should be 1 and ComponentCount should be 2.

### `ComponentCount`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of components of the entry to write out to. Valid values are 1 to 4. For example, if you only wish to output to the y and z components
of a position, then StartComponent should be 1 and ComponentCount should be 2. Note that if *SemanticName* is **NULL** then
*ComponentCount* can be greater than 4 and the described entry will be a gap in the stream out where no data will be written.

### `OutputSlot`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The associated stream output buffer that is bound to the pipeline
(see [ID3D11DeviceContext::SOSetTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-sosettargets)).
The valid range for *OutputSlot* is 0 to 3.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)