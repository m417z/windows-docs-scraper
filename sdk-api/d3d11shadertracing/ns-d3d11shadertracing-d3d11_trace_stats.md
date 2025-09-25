## Description

Specifies statistics about a trace.

## Members

### `TraceDesc`

A [D3D11_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_shader_trace_desc) structure that describes the shader trace object for which this structure specifies statistics.

### `NumInvocationsInStamp`

The number of calls in the stamp for the trace. This value is always 1 for vertex shaders, hull shaders, domain shaders, geometry shaders, and compute shaders. This value is 4 for pixel shaders.

### `TargetStampIndex`

The index of the target stamp. This value is always 0 for vertex shaders, hull shaders, domain shaders, geometry shaders, and compute shaders. However, for pixel shaders this value indicates which of the four pixels in the stamp is the target for the trace. You can examine the traces for other pixels in the stamp to determine how derivative calculations occurred. You can make this determination by correlating the registers across traces.

### `NumTraceSteps`

The total number of steps for the trace. This number is the same for all stamp calls.

### `InputMask`

The component trace mask for each input v# register. For information about D3D11_TRACE_COMPONENT_MASK, see [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value).

For vertex shaders, geometry shaders, pixel shaders, hull shaders, and domain shaders, the valid range is [0..31]. For compute shaders, this member is not applicable. Also, inputs for geometry shaders are 2D-indexed. For example, consider v[vertex][attribute]. In this example, the range of [attribute] is [0..31]. The [vertex] axis is the same size for all inputs, which are determined by the **GSInputPrimitive** member.

Similarly, inputs for hull shader and domain shader are 2D-indexed. For example, consider v[vertex][attribute]. In this example, the range of [attribute] is [0..15]. The [vertex] axis is the same size for all inputs.

### `OutputMask`

The component trace mask for each output o# register. For information about D3D11_TRACE_COMPONENT_MASK, see [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value).

For vertex shaders and geometry shaders, the valid range is [0..31]. For pixel shaders, the valid range is [0..7]. For compute shaders, this member is not applicable. For output control points for hull shaders, the registers are 2D-indexed. For example, consider ocp[vertex][attribute]. In this example, the range of [attribute] is [0..31]. The [vertex] axis is the same size for all inputs.

### `NumTemps`

The number of temps, that is, 4x32 bit r# registers that are declared.

### `MaxIndexableTempIndex`

The maximum index #+1 of all indexable temps x#[] that are declared. If they are declared sparsely (for example, x3[12] and x200[30] only), this value is 201 (200+1).

### `IndexableTempSize`

The number of temps for each indexable temp x#[numTemps]. You can only have temps up to the value in the **MaxIndexableTempIndex** member.

### `ImmediateConstantBufferSize`

The number of 4x32 bit values (if any) that are in the immediate constant buffer.

### `PixelCoverageMask`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates which MSAA samples are covered for each stamp. This coverage occurs before alpha-to-coverage, depth, and stencil operations are performed on the pixel. For non-MSAA, examine the least significant bit (LSB). This mask can be 0 for pixels that are only executed to support derivatives for neighboring pixels.

### `PixelDiscardedMask`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates discarded samples. If the pixel shader runs at pixel-frequency, "discard" turns off all the samples. If all the samples are off, the following four mask members are also 0.

### `PixelCoverageMaskAfterShader`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates the MSAA samples that are covered. For non-MSAA, examine the LSB.

### `PixelCoverageMaskAfterA2CSampleMask`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates the MSAA samples that are covered after alpha-to-coverage+sampleMask, but before depth and stencil. For non-MSAA, examine the LSB.

### `PixelCoverageMaskAfterA2CSampleMaskDepth`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates the MSAA samples that are covered after alpha-to-coverage+sampleMask+depth, but before stencil. For non-MSAA, examine the LSB.

### `PixelCoverageMaskAfterA2CSampleMaskDepthStencil`

**Note** This member is for pixel shaders only, [stampIndex].

A mask that indicates the MSAA samples that are covered after alpha-to-coverage+sampleMask+depth+stencil. For non-MSAA, examine the LSB.

### `PSOutputsDepth`

A value that specifies whether this trace is for a pixel shader that outputs the oDepth register. TRUE indicates that the pixel shader outputs the oDepth register; otherwise, FALSE.

### `PSOutputsMask`

A value that specifies whether this trace is for a pixel shader that outputs the oMask register. TRUE indicates that the pixel shader outputs the oMask register; otherwise, FALSE.

### `GSInputPrimitive`

A [D3D11_TRACE_GS_INPUT_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_gs_input_primitive)-typed value that identifies the type of geometry shader input primitive. That is, this value identifies: {point, line, triangle, line_adj, triangle_adj} or the number of vertices: 1, 2, 3, 4, or 6 respectively. For example, for a line, input v[][#] is actually v[2][#]. For vertex shaders and pixel shaders, set this member to [D3D11_TRACE_GS_INPUT_PRIMITIVE_UNDEFINED](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_gs_input_primitive).

### `GSInputsPrimitiveID`

A value that specifies whether this trace is for a geometry shader that inputs the PrimitiveID register. TRUE indicates that the geometry shader inputs the PrimitiveID register; otherwise, FALSE.

### `HSOutputPatchConstantMask`

**Note** This member is for hull shaders only.

The component trace mask for the hull-shader output. For information about D3D11_TRACE_COMPONENT_MASK, see [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value).

The [D3D11_TRACE_INPUT_PRIMITIVE_ID_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_register_type) value is available through a call to the [ID3D11ShaderTrace::GetInitialRegisterContents](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getinitialregistercontents) method.

### `DSInputPatchConstantMask`

**Note** This member is for domain shaders only.

The component trace mask for the domain-shader input. For information about D3D11_TRACE_COMPONENT_MASK, see [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value).

The following values are available through a call to the [ID3D11ShaderTrace::GetInitialRegisterContents](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getinitialregistercontents) method:

* [D3D11_TRACE_INPUT_PRIMITIVE_ID_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_register_type)
* [D3D11_TRACE_INPUT_DOMAIN_POINT_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_register_type)

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace::GetTraceStats](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-gettracestats)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)