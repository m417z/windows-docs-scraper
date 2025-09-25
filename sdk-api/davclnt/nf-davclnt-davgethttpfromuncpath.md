# DavGetHTTPFromUNCPath function

## Description

Converts the specified UNC path to an equivalent HTTP path.

## Parameters

### `UncPath` [in]

A pointer to a **null**-terminated Unicode string that contains the UNC path. This path must be in the following format:

\\*server*[@SSL][@*port*][\*path*]

where

* *server* is the server name.
* @SSL is optional and indicates a request for an SSL connection.
* *port* is an optional port number. The standard ports are 80 for http and 443 for https (SSL).
* *path* is optional and specifies a path to a remote file or directory on the server.

### `Url` [out]

A pointer to a caller-allocated buffer that receives the HTTP path as a **null**-terminated Unicode string.

### `lpSize` [in, out]

A pointer to a variable that on input specifies the maximum size, in Unicode characters, of the buffer that the *HttpPath* parameter points to. If the function succeeds, on output the variable receives the number of characters that were copied into the buffer. If the function fails with ERROR_INSUFFICIENT_BUFFER, on output the variable receives the number of characters needed to store the HTTP path, including the "http://" or "https://" prefix and the terminating **NULL** character.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer that the *HttpPath* parameter points to was not large enough to store the HTTP path. |