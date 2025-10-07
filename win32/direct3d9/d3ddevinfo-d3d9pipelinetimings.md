# D3DDEVINFO\_D3D9PIPELINETIMINGS structure

Percent of time processing data in the pipeline.

## Members

**VertexProcessingTimePercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time spent running vertex shaders.

**PixelProcessingTimePercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time spent running pixel shaders.

**OtherGPUProcessingTimePercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time spent doing other processing.

**GPUIdleTimePercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time not processing anything.

## Remarks

For best performance, a balanced load is recommended.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetData**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata)

