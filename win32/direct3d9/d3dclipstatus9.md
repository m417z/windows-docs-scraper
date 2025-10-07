# D3DCLIPSTATUS9 structure

Describes the current clip status.

## Members

**ClipUnion**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Clip union flags that describe the current clip status. This member can be one or more of the following flags:

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
|

**D3DCS\_ALL**

| Combination of all clip flags.<br> |
|

**D3DCS\_LEFT**

| All vertices are clipped by the left plane of the viewing frustum.<br> |
|

**D3DCS\_RIGHT**

| All vertices are clipped by the right plane of the viewing frustum.<br> |
|

**D3DCS\_TOP**

| All vertices are clipped by the top plane of the viewing frustum.<br> |
|

**D3DCS\_BOTTOM**

| All vertices are clipped by the bottom plane of the viewing frustum.<br> |
|

**D3DCS\_FRONT**

| All vertices are clipped by the front plane of the viewing frustum.<br> |
|

**D3DCS\_BACK**

| All vertices are clipped by the back plane of the viewing frustum.<br> |
|

**D3DCS\_PLANE0**

| Application-defined clipping planes.<br> |
|

**D3DCS\_PLANE1**

| Application-defined clipping planes.<br> |
|

**D3DCS\_PLANE2**

| Application-defined clipping planes.<br> |
|

**D3DCS\_PLANE3**

| Application-defined clipping planes.<br> |
|

**D3DCS\_PLANE4**

| Application-defined clipping planes.<br> |
|

**D3DCS\_PLANE5**

| Application-defined clipping planes.<br> |

**ClipIntersection**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Clip intersection flags that describe the current clip status. This member can take the same flags as ClipUnion.

## Remarks

When clipping is enabled during vertex processing (by [**ProcessVertices**](https://learn.microsoft.com/windows/desktop/api), [**DrawPrimitive**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawprimitive), or other drawing functions), Direct3D computes a clip code for every vertex. The clip code is a combination of D3DCS\_\* bits. When a vertex is outside a particular clipping plane, the corresponding bit is set in the clipping code. Direct3D maintains the clip status using **D3DCLIPSTATUS9**, which has ClipUnion and ClipIntersection members. ClipUnion is a bitwise OR of all vertex clip codes and ClipIntersection is a bitwise AND of all vertex clip codes. Initial values are zero for ClipUnion and 0xFFFFFFFF for ClipIntersection. When D3DRS\_CLIPPING is set to **FALSE**, ClipUnion and ClipIntersection are set to zero. Direct3D updates the clip status during drawing calls. To compute clip status for a particular object, set ClipUnion and ClipIntersection to their initial value and continue drawing.

Clip status is not updated by [**DrawRectPatch**](https://learn.microsoft.com/windows/desktop/api) and [**DrawTriPatch**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawtripatch) because there is no software emulation for them.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetClipStatus**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getclipstatus)

[**SetClipStatus**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setclipstatus)

