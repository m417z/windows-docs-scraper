# D3DXTRACK\_DESC structure

Describes an animation track and specifies blending weight, speed, and position for the track at a given time.

## Members

**Priority**

Type: **[**D3DXPRIORITY\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpriority-type)**

Priority type, as defined in [**D3DXPRIORITY\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpriority-type).

**Weight**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weight value. The weight determines the proportion of this track to blend with other tracks.

**Speed**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Speed value. This is used similarly to a multiplier to scale the period of the track.

**Position**

Type: **[**DOUBLE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Time position of the track, in the local timeframe of its current animation set.

**Enable**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Track enable/disable. To enable, set to **TRUE**. To disable, set to **FALSE**.

## Remarks

Tracks with the same priority are blended together, and the two resulting values are then blended using the priority blend factor. A track must have an animation set (stored separately) associated with it.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

