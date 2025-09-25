# CM_STATE enumeration

## Description

Specifies column state values. Used by members of the [IColumnManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icolumnmanager) interface through the [CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo) structure.

## Constants

### `CM_STATE_NONE:0`

The column is not currently displayed.

### `CM_STATE_VISIBLE:0x1`

The column is currently displayed.

### `CM_STATE_FIXEDWIDTH:0x2`

The column cannot be resized.

### `CM_STATE_NOSORTBYFOLDERNESS:0x4`

Do not sort folders separately.

### `CM_STATE_ALWAYSVISIBLE:0x8`

The column cannot be hidden.