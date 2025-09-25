# ID2D1RenderInfo::SetInstructionCountHint

## Description

Provides an estimated hint of shader execution cost to D2D.

## Parameters

### `instructionCount`

Type: **UINT32**

An approximate instruction count of the associated shader.

## Remarks

The instruction count may be set according to the number of instructions in the shader. This information is used as a hint when rendering extremely large images. Calling this API is optional, but it may improve performance if you provide an accurate number.

**Note** Instructions that occur in a loop should be counted according to the number of loop iterations.

## See also

[ID2D1RenderInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1renderinfo)