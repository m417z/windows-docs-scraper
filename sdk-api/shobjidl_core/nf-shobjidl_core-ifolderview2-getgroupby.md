# IFolderView2::GetGroupBy

## Description

Retrieves the property and sort order used for grouping items in the folder display.

## Parameters

### `pkey` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) by which the view is grouped.

### `pfAscending` [out]

Type: **BOOL***

A pointer to a value of type **BOOL** that indicates sort order of the groups.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The view is grouped. |
| **S_FALSE** | The view is not grouped. |