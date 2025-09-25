# INewShortcutHookA::GetFolder

## Description

Gets the folder name for the shortcut object.

## Parameters

### `pszFolder` [out]

Type: **PTSTR**

The address of a character buffer that receives the folder name.

### `cchFolder`

Type: **int**

The size of the buffer at *pszFolder*, in characters.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if no folder has been assigned, or a standard error code otherwise.