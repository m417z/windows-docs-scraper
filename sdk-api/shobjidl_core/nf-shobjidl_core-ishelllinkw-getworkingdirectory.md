# IShellLinkW::GetWorkingDirectory

## Description

Gets the name of the working directory for a Shell link object.

## Parameters

### `pszDir`

Type: **LPTSTR**

The address of a buffer that receives the name of the working directory.

### `cch`

Type: **int**

The maximum number of characters to copy to the buffer pointed to by the *pszDir* parameter. The name of the working directory is truncated if it is longer than the maximum specified by this parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.