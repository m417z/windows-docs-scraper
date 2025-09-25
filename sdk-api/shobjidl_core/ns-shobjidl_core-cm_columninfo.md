# CM_COLUMNINFO structure

## Description

Defines column information. Used by members of the [IColumnManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icolumnmanager) interface.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes.

### `dwMask`

Type: **DWORD**

One or more values from the [CM_MASK](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_mask) enumeration that specify which members of this structure are valid.

### `dwState`

Type: **DWORD**

One or more values from the [CM_STATE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_state) enumeration that specify the state of the column.

### `uWidth`

Type: **UINT**

One of the members of the [CM_SET_WIDTH_VALUE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_set_width_value) enumeration that specifies the column width.

### `uDefaultWidth`

Type: **UINT**

The default width of the column.

### `uIdealWidth`

Type: **UINT**

The ideal width of the column.

### `wszName`

Type: **WCHAR[MAX_COLUMN_NAME_LEN]**

A buffer of size MAX_COLUMN_NAME_LEN that contains the name of the column as a null-terminated Unicode string.