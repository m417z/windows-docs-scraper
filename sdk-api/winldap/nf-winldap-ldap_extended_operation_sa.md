# ldap_extended_operation_sA function

## Description

The **ldap_extended_operation_s** function is used to pass extended LDAP operations to the server.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `Oid` [in]

A pointer to a null-terminated string that contains the dotted object identifier (OID) text string that names the request.

### `Data` [in]

The arbitrary data required by the operation. If **NULL**, no data is sent to the server.

### `ServerControls` [in]

Optional. A list of LDAP server controls. Set this parameter to **NULL** if not used.

### `ClientControls` [in]

Optional. A list of client controls. Set this parameter to **NULL** if not used.

### `ReturnedOid` [out]

Optional. A pointer to a null-terminated string that contains the dotted OID text string of the server response message. This is normally the same OID as that which names the request passed to the server in the *Oid* parameter. Set to **NULL** if not used.

### `ReturnedData` [out]

Optional. The arbitrary data returned by the extended operation. If **NULL**, no data is returned by the server. Set this parameter to **NULL** if not used.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_extended_operation_s** function enables a client to send an extended request (free for all) to an LDAP 3 (or later) server. The functionality is open and the client request can be for any operation.

As a synchronous function, **ldap_extended_operation_s** returns any response data in the *ReturnedOid* and *ReturnedData* fields. When no longer required, free the *ReturnedOid* string and the *ReturnedData* buffer by calling
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree). Because *ReturnedData* is not a **PCHAR** data type, it must be explicitly cast when used as an argument of **ldap_memfree**, such as:

```cpp
struct berval *pBV;
ldap_extended_operation_s(......., &pBV);
...
ldap_memfree( (PCHAR) pBV);
```

Multithreading: The **ldap_extended_operation_s** function is thread-safe.

> [!NOTE]
> The winldap.h header defines ldap_extended_operation_s as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_extended_operation](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_extended_operation)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)