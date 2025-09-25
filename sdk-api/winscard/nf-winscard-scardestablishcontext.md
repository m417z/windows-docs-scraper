# SCardEstablishContext function

## Description

The **SCardEstablishContext** function establishes the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (the scope) within which database operations are performed.

## Parameters

### `dwScope` [in]

Scope of the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SCARD_SCOPE_USER** | Database operations are performed within the domain of the user. |
| **SCARD_SCOPE_SYSTEM** | Database operations are performed within the domain of the system. The calling application must have appropriate access permissions for any database actions. |

### `pvReserved1` [in]

Reserved for future use and must be **NULL**. This parameter will allow a suitably privileged management application to act on behalf of another user.

### `pvReserved2` [in]

Reserved for future use and must be **NULL**.

### `phContext` [out]

A handle to the established [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). This handle can now be supplied to other functions attempting to do work within this context.

## Return value

If the function succeeds, the function returns SCARD_S_SUCCESS.

If the function fails, it returns an error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

## Remarks

The context handle returned by **SCardEstablishContext** can be used by database query and management functions. For more information, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions) and
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

To release an established resource manager context, use
[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext).

If the client attempts a smart card operation in a remote session, such as a client session running on a terminal server, and the operating system in use does not support smart card redirection, this function returns ERROR_BROKEN_PIPE.

#### Examples

The following example establishes a resource manager context.

```cpp
SCARDCONTEXT    hSC;
LONG            lReturn;
// Establish the context.
lReturn = SCardEstablishContext(SCARD_SCOPE_USER,
                                NULL,
                                NULL,
                                &hSC);
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardEstablishContext\n");
else
{
    // Use the context as needed. When done,
    // free the context by calling SCardReleaseContext.
    // ...
}

```

## See also

[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext)