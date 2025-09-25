# D3D12_LOGIC_OP enumeration

## Description

Defines constants that specify logical operations to configure for a render target.

## Constants

### `D3D12_LOGIC_OP_CLEAR:0`

Clears the render target (`0`).

### `D3D12_LOGIC_OP_SET`

Sets the render target ( `1`).

### `D3D12_LOGIC_OP_COPY`

Copys the render target (`` s source from Pixel Shader output).

### `D3D12_LOGIC_OP_COPY_INVERTED`

Performs an inverted-copy of the render target (~s).

### `D3D12_LOGIC_OP_NOOP`

No operation is performed on the render target (d destination in the Render Target View).

### `D3D12_LOGIC_OP_INVERT`

Inverts the render target (~d).

### `D3D12_LOGIC_OP_AND`

Performs a logical AND operation on the render target (s & d).

### `D3D12_LOGIC_OP_NAND`

Performs a logical NAND operation on the render target (~(s & d)).

### `D3D12_LOGIC_OP_OR`

Performs a logical OR operation on the render target (s | d).

### `D3D12_LOGIC_OP_NOR`

Performs a logical NOR operation on the render target (~(s | d)).

### `D3D12_LOGIC_OP_XOR`

Performs a logical XOR operation on the render target (s ^ d).

### `D3D12_LOGIC_OP_EQUIV`

Performs a logical equal operation on the render target (~(s ^ d)).

### `D3D12_LOGIC_OP_AND_REVERSE`

Performs a logical AND and reverse operation on the render target (s & ~d).

### `D3D12_LOGIC_OP_AND_INVERTED`

Performs a logical AND and invert operation on the render target (~s & d).

### `D3D12_LOGIC_OP_OR_REVERSE`

Performs a logical OR and reverse operation on the render target (s | ~d).

### `D3D12_LOGIC_OP_OR_INVERTED`

Performs a logical OR and invert operation on the render target (~s | d).

## Remarks

This enum is used by the D3D12_RENDER_TARGET_BLEND_DESC structure.

## See also

Core Enumerations ``