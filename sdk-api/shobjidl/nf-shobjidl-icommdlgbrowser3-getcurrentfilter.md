# ICommDlgBrowser3::GetCurrentFilter

## Description

Gets the current filter as a Unicode string.

## Parameters

### `pszFileSpec` [out]

Type: **LPWSTR**

Contains a pointer to the current filter path/file as a Unicode string.

### `cchFileSpec` [in]

Type: **int**

Specifies the path/file length, in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.