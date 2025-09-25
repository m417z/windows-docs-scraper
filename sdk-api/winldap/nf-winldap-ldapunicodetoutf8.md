# LdapUnicodeToUTF8 function

## Description

The **LdapUnicodeToUTF8** function converts Unicode strings to UTF-8. Modules that do not have the UTF-8 code page can call this function.

## Parameters

### `lpSrcStr` [in]

A pointer to a null-terminated Unicode string to convert.

### `cchSrc` [in]

An integer that specifies the size, in characters, of the *lpSrcStr* string.

### `lpDestStr` [out]

A pointer to a buffer that receives the converted UTF-8 character string, without a null terminator.

### `cchDest` [in]

An integer that specifies the size, in characters, of the *lpDestStr* buffer.

## Return value

The return value is the size, in characters, written to the *lpDestStr* buffer.
If the *lpDestStr* buffer is too small, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**.

When the *cchDest* parameter is zero, the required size of the destination buffer is returned.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LdapUTF8ToUnicode](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldaputf8tounicode)