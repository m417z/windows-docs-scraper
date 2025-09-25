# D3DVSHADERCAPS2_0 structure

## Description

Vertex shader caps.

## Members

### `Caps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Instruction predication is supported if this value is nonzero. See [setp_comp - vs](https://learn.microsoft.com/windows/desktop/direct3dhlsl/setp-comp---vs).

### `DynamicFlowControlDepth`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

 Either 0 or 24, which represents the depth of the dynamic flow control instruction nesting. See [D3DVS20CAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvs20caps).

### `NumTemps`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of temporary registers supported. See [D3DVS20CAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvs20caps).

### `StaticFlowControlDepth`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth of nesting of the [loop - vs](https://learn.microsoft.com/windows/desktop/direct3dhlsl/loop---vs)/[rep - vs](https://learn.microsoft.com/windows/desktop/direct3dhlsl/rep---vs) and [call - vs](https://learn.microsoft.com/windows/desktop/direct3dhlsl/call---vs)/[callnz bool - vs](https://learn.microsoft.com/windows/desktop/direct3dhlsl/callnz-bool---vs) instructions. See [D3DVS20CAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvs20caps).

## See also

[D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9)

[D3DPSHADERCAPS2_0](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dpshadercaps2_0)

[Direct3D Structures](https://learn.microsoft.com/windows/desktop/direct3d9/dx9-graphics-reference-d3d-structures)