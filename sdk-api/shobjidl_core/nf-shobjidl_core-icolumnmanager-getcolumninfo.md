# IColumnManager::GetColumnInfo

## Description

Gets information about each column: width, visibility, display name, and state.

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pcmci` [in, out]

Type: **[CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo)***

A pointer to a [CM_COLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-cm_columninfo) structure. On entry, set this structure's **dwMask** member to specify the information to retrieve. Also set its **cbSize** member. When this method returns successfully, the structure contains the requested information.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Column information obtained. |
| **failure** | Column information not obtained. |
| **E_INVALIDARG** | Indicates that cbSize member of *pcmci* does not equal the size of CM_COLUMNINFO. |