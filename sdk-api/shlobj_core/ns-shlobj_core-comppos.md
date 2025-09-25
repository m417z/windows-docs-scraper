# COMPPOS structure

## Description

Holds information about a component's position and size.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure.

### `iLeft`

Type: **int**

The left edge of the top-left corner in screen coordinates. Set to COMPONENT_DEFAULT_LEFT to let the Shell decide the position.

### `iTop`

Type: **int**

The top of the top-left corner in screen coordinates. Set to COMPONENT_DEFAULT_TOP to let the Shell decide the position.

### `dwWidth`

Type: **DWORD**

The width, in pixels.

### `dwHeight`

Type: **DWORD**

The height, in pixels.

### `izIndex`

Type: **int**

The z-order of the component.

### `fCanResize`

Type: **BOOL**

Set to **TRUE** if the component is resizable, **FALSE** if not.

### `fCanResizeX`

Type: **BOOL**

Set to **TRUE** if the component is resizable in the x direction, **FALSE** if not.

### `fCanResizeY`

Type: **BOOL**

Set to **TRUE** if the component is resizable in the y direction, **FALSE** if not.

### `iPreferredLeftPercent`

Type: **int**

The left edge of the upper-left corner as a percentage of screen width.

### `iPreferredTopPercent`

Type: **int**

The top of the upper-left corner as a percentage of screen width.