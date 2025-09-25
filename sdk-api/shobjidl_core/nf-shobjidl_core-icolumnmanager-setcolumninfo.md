# IColumnManager::SetColumnInfo

## Description

Sets the state for a specified column.

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that identifies the column.

### `pcmci` [in]

Type: **const [CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo)***

A pointer to a [CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo) structure that contains the state to set for this column.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Column state set. |
| **failure** | Column state not set. |
| **E_INVALIDARG** | The *pcmci* parameter is **NULL**. |