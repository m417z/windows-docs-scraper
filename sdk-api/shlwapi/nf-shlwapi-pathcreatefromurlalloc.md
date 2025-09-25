# PathCreateFromUrlAlloc function

## Description

Creates a path from a file URL.

## Parameters

### `pszIn` [in]

Type: **PCWSTR**

A pointer to the URL of a file, represented as a null-terminated, Unicode string.

### `ppszOut` [out]

Type: **PWSTR***

The address of a pointer to a buffer of length MAX_PATH that, when this function returns successfully, receives the file path.

### `dwFlags`

Type: **DWORD**

Reserved, must be 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.