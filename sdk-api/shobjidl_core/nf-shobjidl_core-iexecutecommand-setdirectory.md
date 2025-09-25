# IExecuteCommand::SetDirectory

## Description

Sets a new working directory.

## Parameters

### `pszDirectory` [in]

Type: **LPCWSTR**

Pointer to a null-terminated string with the fully qualified path of the new working directory. If this value is **NULL**, the current working directory is used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.