# COMPSTATEINFO structure

## Description

Used by Windows 2000 to hold information about a component's state.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure.

### `iLeft`

Type: **int**

The left edge of the top-left corner in screen coordinates.

### `iTop`

Type: **int**

The top of the top-left corner in screen coordinates.

### `dwWidth`

Type: **DWORD**

The width, in pixels.

### `dwHeight`

Type: **DWORD**

The height, in pixels.

### `dwItemState`

Type: **DWORD**

The state of the component.

#### IS_NORMAL

Normal screen.

#### IS_FULLSCREEN

Full screen.

#### IS_SPLIT

Split screen.