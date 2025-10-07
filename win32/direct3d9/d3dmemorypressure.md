# D3DMEMORYPRESSURE structure (D3d9types.h)

Contains data for memory pressure reporting.

## Members

**BytesEvictedFromProcess**

Type: **[**UINT64**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of bytes that were evicted by the process during the duration of the query.

**SizeOfInefficientAllocation**

Type: **[**UINT64**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The total number of bytes placed in nonoptimal memory segments, due to inadequate space within the preferred memory segments.

**LevelOfEfficiency**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The overall efficiency of the memory allocations that were placed in nonoptimal memory. The value is expressed as a percentage. For example, the value 95 indicates that the allocations placed in nonpreferred memory segments are 95% efficient. This number should not be considered an exact measurement.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

