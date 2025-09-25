# _D3DDDIBOX structure

## Description

Describes the bounds of a volume texture.

## Members

### `Left` [in]

The position of the left side of the box on the x-axis.

### `Top` [in]

The position of the top of the box on the y-axis.

### `Right` [in]

The position of the right side of the box on the x-axis.

### `Bottom` [in]

The position of the bottom of the box on the y-axis.

### `Front`

 [in] The position of the front of the box on the z-axis.

### `Back` [in]

The position of the back of the box on the z-axis.

## Remarks

The height of the volume equals the value in the **Bottom** member minus the value in the **Top** member (that is, height = bottom – top).

The width of the volume equals the value in the **Right** member minus the value in the **Left** member (that is, width = right – left).

The depth of the volume equals the value in the **Back** member minus the value in the **Front** member (that is, depth = back – front).