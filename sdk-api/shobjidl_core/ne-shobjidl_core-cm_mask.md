# CM_MASK enumeration

## Description

Indicates which values in the [CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo) structure should be set during calls to [IColumnManager::SetColumnInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icolumnmanager-setcolumninfo).

## Constants

### `CM_MASK_WIDTH:0x1`

The **uWidth** member is specified.

### `CM_MASK_DEFAULTWIDTH:0x2`

The **uDefaultWidth** member is specified.

### `CM_MASK_IDEALWIDTH:0x4`

The **uIdealWidth** member is specified.

### `CM_MASK_NAME:0x8`

The **wszName** member is specified.

### `CM_MASK_STATE:0x10`

The **dwState** member is specified.