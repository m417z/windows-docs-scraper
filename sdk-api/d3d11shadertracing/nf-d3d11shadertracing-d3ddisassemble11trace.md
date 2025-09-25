# D3DDisassemble11Trace function

## Description

Disassembles a section of compiled Microsoft High Level Shader Language (HLSL) code that is specified by shader trace steps.

## Parameters

### `pSrcData` [in]

Type: **LPCVOID**

A pointer to compiled shader data.

### `SrcDataSize` [in]

Type: **SIZE_T**

The size, in bytes, of the block of memory that pSrcData points to.

### `pTrace` [in]

Type: **ID3D11ShaderTrace***

A pointer to the ID3D11ShaderTrace interface for the shader trace information object.

### `StartStep` [in]

Type: **UINT**

The number of the step in the trace from which D3DDisassemble11Trace starts the disassembly.

### `NumSteps` [in]

Type: **UINT**

The number of trace steps to disassemble.

### `Flags` [in]

Type: **UINT**

A combination of zero or more of the following flags that are combined by using a bitwise OR operation. The resulting value specifies how D3DDisassemble11Trace disassembles the compiled shader data.

| Flag | Description |
| --- | --- |
| D3D_DISASM_ENABLE_COLOR_CODE (0x01) | Enable the output of color codes. |
| D3D_DISASM_ENABLE_DEFAULT_VALUE_PRINTS (0x02) | Enable the output of default values. |
| D3D_DISASM_ENABLE_INSTRUCTION_NUMBERING (0x04) | Enable instruction numbering. |
| D3D_DISASM_ENABLE_INSTRUCTION_CYCLE (0x08) | No effect. |
| D3D_DISASM_DISABLE_DEBUG_INFO (0x10) | Disable the output of debug information. |
| D3D_DISASM_ENABLE_INSTRUCTION_OFFSET (0x20) | Enable the output of instruction offsets. |
| D3D_DISASM_INSTRUCTION_ONLY (0x40) | Enable the output of the instruction cycle per step in D3DDisassemble11Trace. This flag is similar to the D3D_DISASM_ENABLE_INSTRUCTION_NUMBERING and D3D_DISASM_ENABLE_INSTRUCTION_OFFSET flags.<br><br>This flag has no effect in the D3DDisassembleRegion function. Cycle information comes from the trace; therefore, cycle information is available only in the trace disassembly. |

### `ppDisassembly` [out]

Type: **ID3D10Blob****

A pointer to a buffer that receives the ID3DBlob interface that accesses the disassembled HLSL code.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT error code.

## Remarks

D3DDisassemble11Trace walks the steps of a shader trace and outputs appropriate disassembly for each step that is based on the step's instruction index. The disassembly is annotated with register-value information from the trace. The behavior of D3DDisassemble11Trace differs from D3DDisassemble in that instead of the static disassembly of a compiled shader that D3DDisassemble performs, D3DDisassemble11Trace provides an execution trace that is based on the shader trace information.

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-functions)