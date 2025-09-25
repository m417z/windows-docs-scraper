# IExecuteCommand::SetParameters

## Description

Provides parameter values for the verb.

## Parameters

### `pszParameters` [in]

Type: **LPCWSTR**

Pointer to a string that contains parameter values. The format and contents of this string is determined by the verb that is to be invoked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.