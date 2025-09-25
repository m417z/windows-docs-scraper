# IColumnManager::SetColumns

## Description

Sets the collection of columns for the view to display.

## Parameters

### `rgkeyOrder` [in]

Type: **const [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures that specify the columns to display.

### `cVisible` [in]

Type: **UINT**

The size of the *rgkeyOrder* array.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Collection set. |
| **failure** | Collection not set. |

## Remarks

**Note** **IColumnManager::SetColumns** clears the state of all columns, so [IColumnManager::SetColumnInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icolumnmanager-setcolumninfo) must be called afterward to set the state of individual columns.