# D3D11_TRACE_STEP structure

## Description

Describes a trace step, which is an instruction.

## Members

### `ID`

A number that identifies the instruction, as an offset into the executable instructions that are present in the shader.

HLSL debugging information uses the same convention. Therefore, HLSL instructions are matched to a set of IDs. You can then map an ID to a disassembled string that can be displayed to the user.

### `InstructionActive`

A value that specifies whether the instruction is active. This value is TRUE if something happened; therefore, you should parse other data in this structure. Otherwise, nothing happened; for example, if an instruction is disabled due to flow control even though other pixels in the stamp execute it.

### `NumRegistersWritten`

The number of registers for the instruction that are written to. The range of registers is [0...NumRegistersWritten-1]. You can pass a register number to the *writtenRegisterIndex* parameter of [ID3D11ShaderTrace::GetWrittenRegister](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getwrittenregister) to retrieve individual write-register information.

### `NumRegistersRead`

The number of registers for the instruction that are read from. The range of registers is [0...NumRegistersRead-1]. You can pass a register number to the *readRegisterIndex* parameter of [ID3D11ShaderTrace::GetReadRegister](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getreadregister) to retrieve individual read-register information.

### `MiscOperations`

A combination of the following values that are combined by using a bitwise **OR** operation. The resulting value specifies the mask for the trace miscellaneous operations. These flags indicate the possible effect of a shader operation when it does not write any output registers. For example, the "add r0, r1 ,r2" operation writes to the r0 register; therefore, you can look at the trace-written register's information to determine what the operation changed. However, some shader instructions do not write any registers, but still effect those registers.

| Flag | Description |
| --- | --- |
| D3D11_TRACE_MISC_GS_EMIT (0x1) | The operation was a geometry shader data emit. |
| D3D11_TRACE_MISC_GS_CUT (0x2) | The operation was a geometry shader strip cut. |
| D3D11_TRACE_MISC_PS_DISCARD (0x4) | The operation was a pixel shader discard, which rejects the pixel. |
| D3D11_TRACE_MISC_GS_EMIT_STREAM (0x8) | Same as D3D11_TRACE_MISC_GS_EMIT, except in [shader model 5](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl) where you can specify a particular stream to emit to. |
| D3D11_TRACE_MISC_GS_CUT_STREAM (0x10) | Same as D3D11_TRACE_MISC_GS_CUT, except in [shader model 5](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl) where you can specify a particular stream to strip cut. |
| D3D11_TRACE_MISC_HALT (0x20) | The operation was a shader halt instruction, which stops shader execution. The HLSL [abort](https://learn.microsoft.com/windows/desktop/direct3dhlsl/abort) intrinsic function causes a halt. |
| D3D11_TRACE_MISC_MESSAGE (0x40) | The operation was a shader message output, which can be logged to the information queue. The HLSL [printf](https://learn.microsoft.com/windows/desktop/direct3dhlsl/printf) and [errorf](https://learn.microsoft.com/windows/desktop/direct3dhlsl/errorf) intrinsic functions cause messages. |

If the **NumRegistersWritten** member is 0, examine this member although this member still might be empty (0).

### `OpcodeType`

A number that specifies the type of instruction (for example, [add](https://learn.microsoft.com/windows/desktop/direct3dhlsl/add---vs), [mul](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-mul), and so on). You can ignore this member if you do not know the number for the instruction type. This member offers a minor convenience at the cost of bloating the trace slightly. You can use the **ID** member and map back to the original shader code to retrieve the full information about the instruction.

### `CurrentGlobalCycle`

The global cycle count for this step. You can use this member to correlate parallel thread execution via multiple simultaneous traces, for example, for the compute shader.

**Note** Multiple threads at the same point in execution might log the same **CurrentGlobalCycle**.

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)