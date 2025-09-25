# IWbemPath::GetServer

## Description

The
**IWbemPath::GetServer** method retrieves the server portion of the path.

## Parameters

### `puNameBufLength` [in, out]

Upon input, this is the size in characters of the buffer pointed to by *pszName*. Upon return, this is the number of characters in the server name, including the **NULL** terminator.

### `pName` [in, out]

Server name.

## Return value

This method returns the following values.

## Remarks

This method can be used to determine how big a buffer is needed for *pszName*. This is done by passing in a **NULL** pointer for the buffer, setting *puNameBufLength* to 0 (zero) and then making the call. Upon return, *puNameBufLength* indicates how large a buffer is needed for *pszName* and its terminating **NULL** character.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)