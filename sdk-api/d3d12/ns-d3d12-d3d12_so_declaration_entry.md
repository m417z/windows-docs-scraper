# D3D12_SO_DECLARATION_ENTRY structure

## Description

Describes a vertex element in a vertex buffer in an output slot.

## Members

### `Stream`

Zero-based, stream number.

### `SemanticName`

Type of output element; possible values include: **"POSITION"**, **"NORMAL"**, or **"TEXCOORD0"**.
Note that if **SemanticName** is **NULL** then
**ComponentCount** can be greater than 4 and the described entry will be a gap in the stream out where no data will be written.

### `SemanticIndex`

Output element's zero-based index. Use, for example, if you have more than one texture coordinate stored in each vertex.

### `StartComponent`

The component of the entry to begin writing out to. Valid values are 0 to 3. For example, if you only wish to output to the y and z components
of a position, **StartComponent** is 1 and **ComponentCount** is 2.

### `ComponentCount`

The number of components of the entry to write out to. Valid values are 1 to 4. For example, if you only wish to output to the y and z components
of a position, **StartComponent** is 1 and **ComponentCount** is 2. Note that if **SemanticName** is **NULL** then
**ComponentCount** can be greater than 4 and the described entry will be a gap in the stream out where no data will be written.

### `OutputSlot`

The associated stream output buffer that is bound to the pipeline.
The valid range for **OutputSlot** is 0 to 3.

## Remarks

Specify an array of **D3D12_SO_DECLARATION_ENTRY** structures in the **pSODeclaration** member of a [D3D12_STREAM_OUTPUT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_stream_output_desc) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)