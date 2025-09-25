# D3DDisassembleRegion function

## Description

Disassembles a specific region of compiled Microsoft High Level Shader Language (HLSL) code.

## Parameters

### `pSrcData` [in]

A pointer to compiled shader data.

### `SrcDataSize` [in]

The size, in bytes, of the block of memory that *pSrcData* points to.

### `Flags` [in]

A combination of zero or more of the following flags that are combined by using a bitwise **OR** operation. The resulting value specifies how **D3DDisassembleRegion** disassembles the compiled shader data.

| Flag | Description |
| --- | --- |
| D3D_DISASM_ENABLE_COLOR_CODE (0x01) | Enable the output of color codes. |
| D3D_DISASM_ENABLE_DEFAULT_VALUE_PRINTS (0x02) | Enable the output of default values. |
| D3D_DISASM_ENABLE_INSTRUCTION_NUMBERING (0x04) | Enable instruction numbering. |
| D3D_DISASM_ENABLE_INSTRUCTION_CYCLE (0x08) | No effect. |
| D3D_DISASM_DISABLE_DEBUG_INFO (0x10) | Disable the output of debug information. |
| D3D_DISASM_ENABLE_INSTRUCTION_OFFSET (0x20) | Enable the output of instruction offsets. |
| D3D_DISASM_INSTRUCTION_ONLY (0x40) | This flag has no effect in **D3DDisassembleRegion**. Cycle information comes from the trace; therefore, cycle information is available only in [D3DDisassemble11Trace](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3ddisassemble11trace)'s trace disassembly. |

### `szComments` [in, optional]

A pointer to a constant null-terminated string at the top of the shader that identifies the shader constants and variables.

### `StartByteOffset` [in]

The number of bytes offset into the compiled shader data where **D3DDisassembleRegion** starts the disassembly.

### `NumInsts` [in]

The number of instructions to disassemble.

### `pFinishByteOffset` [out, optional]

A pointer to a variable that receives the number of bytes offset into the compiled shader data where **D3DDisassembleRegion** finishes the disassembly.

### `ppDisassembly` [out]

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that accesses the disassembled HLSL code.

## Return value

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DDisassembleRegion** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)