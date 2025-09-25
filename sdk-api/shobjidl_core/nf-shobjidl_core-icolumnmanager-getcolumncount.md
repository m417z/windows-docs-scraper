# IColumnManager::GetColumnCount

## Description

Gets the column count for either the visible columns or the complete set of columns.

## Parameters

### `dwFlags` [in]

Type: **[CM_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_enum_flags)**

A value from the [CM_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_enum_flags) enumeration that specifies whether to show only visible columns or all columns regardless of visibility.

### `puCount` [out]

Type: **UINT***

Contains a pointer to the column count.

## Return value

Type: **HRESULT**

Always returns S_OK.