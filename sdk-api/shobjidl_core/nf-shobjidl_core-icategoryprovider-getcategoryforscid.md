# ICategoryProvider::GetCategoryForSCID

## Description

Gets a GUID that represents the categorizer to use for the specified Shell column.

## Parameters

### `pscid` [in]

Type: **const [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)***

A pointer to a [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure.

### `pguid` [out]

Type: **GUID***

When this method returns, contains a pointer to a GUID that represents the categorizer to use for the [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) pointed to by *pscid*.

## Return value

Type: **HRESULT**

Returns either S_OK on success or S_FALSE on failure.