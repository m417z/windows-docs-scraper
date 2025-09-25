# IShellItem2::GetString

## Description

Gets the string value of a specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `ppsz` [out]

Type: **LPWSTR***

A pointer to a Unicode string value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.