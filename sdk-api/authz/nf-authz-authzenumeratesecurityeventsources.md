# AuthzEnumerateSecurityEventSources function

## Description

The **AuthzEnumerateSecurityEventSources** function retrieves the registered security event sources that are not installed by default.

## Parameters

### `dwFlags` [in]

Reserved for future use; set this parameter to zero.

### `Buffer` [out]

A pointer to an array of [AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration) structures that returns the registered security event sources.

### `pdwCount` [out]

A pointer to a variable that receives the number of event sources found.

### `pdwLength` [in, out]

A pointer to a variable that specifies the length of the *Buffer* parameter in bytes. On output, this parameter receives the number of bytes used or required.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AUTHZ_SOURCE_SCHEMA_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_source_schema_registration)