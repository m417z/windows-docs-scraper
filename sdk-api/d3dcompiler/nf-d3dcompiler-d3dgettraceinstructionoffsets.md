# D3DGetTraceInstructionOffsets function

## Description

Retrieves the byte offsets for instructions within a section of shader code.

## Parameters

### `pSrcData` [in]

A pointer to the compiled shader data.

### `SrcDataSize` [in]

The size, in bytes, of the block of memory that *pSrcData* points to.

### `Flags` [in]

A combination of the following flags that are combined by using a bitwise **OR** operation. The resulting value specifies how **D3DGetTraceInstructionOffsets** retrieves the instruction offsets.

| Flag | Description |
| --- | --- |
| D3D_GET_INST_OFFSETS_INCLUDE_NON_EXECUTABLE (0x01) | Include non-executable code in the retrieved information. |

### `StartInstIndex` [in]

The index of the instruction in the compiled shader data for which **D3DGetTraceInstructionOffsets** starts to retrieve the byte offsets.

### `NumInsts` [in]

The number of instructions for which **D3DGetTraceInstructionOffsets** retrieves the byte offsets.

### `pOffsets` [out, optional]

A pointer to a variable that receives the actual number of offsets.

### `pTotalInsts` [out, optional]

A pointer to a variable that receives the total number of instructions in the section of shader code.

## Return value

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A new kind of Microsoft High Level Shader Language (HLSL) debugging information from a program database (PDB) file uses instruction-byte offsets within a shader blob (arbitrary-length data buffer). You use **D3DGetTraceInstructionOffsets** to translate to and from instruction indexes.

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DGetTraceInstructionOffsets** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)