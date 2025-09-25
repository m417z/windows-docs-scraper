# INewShortcutHookW::GetName

## Description

Gets the file name of the shortcut object, without the extension.

## Parameters

### `pszName` [out]

Type: **PTSTR**

A pointer to a string that receives the name.

### `cchName`

Type: **int**

The size of the buffer at *pszName*, in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.