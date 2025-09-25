# IShellItem2::GetFileTime

## Description

Gets the date and time value of a specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pft` [out]

Type: **FILETIME***

A pointer to a date and time value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.