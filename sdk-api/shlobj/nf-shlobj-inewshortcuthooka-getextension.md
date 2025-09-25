# INewShortcutHookA::GetExtension

## Description

Gets the file name extension for the shortcut object.

## Parameters

### `pszExtension` [out]

Type: **PTSTR**

Pointer to a string that receives the extension.

### `cchExtension`

Type: **int**

The size of the buffer at *pszExtension*, in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.