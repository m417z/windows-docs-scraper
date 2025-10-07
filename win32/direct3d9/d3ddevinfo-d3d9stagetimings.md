# D3DDEVINFO\_D3D9STAGETIMINGS structure

Percent of time processing shader data.

## Members

**MemoryProcessingPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time in shader spent on memory accesses.

**ComputationProcessingPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Percent of time processing (moving data around in registers or doing mathematical operations).

## Remarks

For best performance, a balanced load is recommended.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetData**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata)

