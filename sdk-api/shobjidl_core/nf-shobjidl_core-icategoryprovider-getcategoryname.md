# ICategoryProvider::GetCategoryName

## Description

Gets the name of the specified category.

## Parameters

### `pguid` [in]

Type: **const GUID***

A pointer to a GUID.

### `pszName` [out]

Type: **LPWSTR**

When this method returns, contains a pointer to a string that receives the name of the category.

### `cch` [in]

Type: **UINT**

An integer that receives the number of characters in the string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.