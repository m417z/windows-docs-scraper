# D3DXEVENT\_DESC structure

Describes an animation event.

## Members

**Type**

Type: **[**D3DXEVENT\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxevent-type)**

Event type, as defined in [**D3DXEVENT\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxevent-type).

**Track**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Event track identifier.

**StartTime**

Type: **[**DOUBLE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Start time of the event in global time.

**Duration**

Type: **[**DOUBLE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Duration of the event in global time.

**Transition**

Type: **[**D3DXTRANSITION\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtransition-type)**

Transition style of the event, as defined in [**D3DXTRANSITION\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtransition-type).

**Weight**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Track weight for the event.

**Speed**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Track speed for the event.

**Position**

Type: **[**DOUBLE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Track position for the event.

**Enable**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Enable flag.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

