# ICurrentWorkingDirectory::GetDirectory

## Description

Gets the current working directory.

## Parameters

### `pwzPath` [out]

Type: **PWSTR**

Pointer to a buffer that, when this method returns successfully, receives the current working directory's fully qualified path as a null-terminated Unicode string.

### `cchSize`

Type: **DWORD**

The size of the buffer in Unicode characters, including the terminating **NULL** character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.