# SHGetLocalizedName function

## Description

Retrieves the localized name of a file in a Shell folder.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a string that specifies the fully qualified path of the file.

### `pszResModule` [out]

Type: **PWSTR**

When this function returns, contains a pointer to a string resource that specifies the localized version of the file name.

### `cch`

Type: **UINT**

When this function returns, contains the size of the string, in **WCHARs**, at *pszResModule*.

### `pidsRes` [out]

Type: **int***

When this function returns, contains a pointer to the ID of the localized file name in the resource file.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.