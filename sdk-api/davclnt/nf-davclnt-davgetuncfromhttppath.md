# DavGetUNCFromHTTPPath function

## Description

Converts the specified HTTP path to an equivalent UNC path.

## Parameters

### `Url` [in]

A pointer to a **null**-terminated Unicode string that contains the HTTP path. This string can be in any of the following formats, where *server* is the server name and *path* is the path to a remote file or directory on the server:

* http://*server*/*path*
* http://*server*
* \\http://*server*/*path*
* \\http://*server*
* https://*server*/*path*
* https://*server*
* \\https://*server*/*path*
* \\https://*server*
* \\*server*\*path*
* \\*server*

### `UncPath` [out]

A pointer to a caller-allocated buffer that receives the UNC path as a **null**-terminated Unicode string.

### `lpSize` [in, out]

A pointer to a variable that on input specifies the maximum size, in Unicode characters, of the buffer that the *UncPath* parameter points to. If the function succeeds, on output the variable receives the number of characters that were copied into the buffer, including the terminating **NULL** character. If the function fails with ERROR_INSUFFICIENT_BUFFER, on output the variable receives the number of characters needed to store the UNC path, including the terminating **NULL** character.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer that the *UncPath* parameter points to was not large enough to store the UNC path. |