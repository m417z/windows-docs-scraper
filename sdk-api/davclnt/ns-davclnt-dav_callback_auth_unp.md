# DAV_CALLBACK_AUTH_UNP structure

## Description

Stores user name and password information that was retrieved by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## Members

### `pszUserName`

A pointer to a string that contains the user name. This string is allocated by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

### `ulUserNameLength`

The length, in WCHAR, of the user name, not including the terminating **NULL** character.

### `pszPassword`

A pointer to a string that contains the password. This string is allocated by [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback).

### `ulPasswordLength`

The length, in WCHAR, of the password, not including the terminating **NULL** character.

## Remarks

This structure is included as a member in the [DAV_CALLBACK_CRED](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_cred) structure.

The [DavFreeCredCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback_freecred) callback function should free only the buffer that the **pBuffer** member points to, not the entire structure.

## See also

[DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob)

[DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback)