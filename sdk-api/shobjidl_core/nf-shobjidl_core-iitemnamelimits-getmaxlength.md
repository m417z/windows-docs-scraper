# IItemNameLimits::GetMaxLength

## Description

Returns the maximum number of characters allowed for a particular name in the namespace under which it is called.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a string containing a name.

### `piMaxNameLen` [out]

Type: **int***

A pointer to the maximum number of characters which can be used in the name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.