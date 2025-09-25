# SecPkgContext_ClientCreds structure

## Description

The **SecPkgContext_ClientCreds** structure specifies client credentials when calling the [QueryContextAttributes (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

This structure is supported only on the server.

## Members

### `AuthBufferLen`

The size, in characters, of the **AuthBuffer** buffer.

### `AuthBuffer`

A pointer to a buffer that represents the client credentials.

## See also

[QueryContextAttributes (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)