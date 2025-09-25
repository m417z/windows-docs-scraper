# IColumnManager::GetColumns

## Description

Gets an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures that represent the columns that the view supports. Includes either all columns or only those currently visible.

## Parameters

### `dwFlags` [in]

Type: **[CM_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_enum_flags)**

A value from the [CM_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-cm_enum_flags) enumeration that specifies whether to show only visible columns or all columns regardless of visibility.

### `rgkeyOrder` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

On success, contains a pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures that represent the columns.

### `cColumns` [in]

Type: **UINT**

The length of the *rgkeyOrder* array.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Collection retrieved. |
| **failure** | All columns were not mapped to [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures. |
| **E_INVALIDARG** | The value in *cColumns* is inconsistent with the value in *dwFlags*. |