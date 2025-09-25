# DAV_CALLBACK_AUTH_BLOB structure

## Description

Stores an authentication [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that was retrieved by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## Members

### `pBuffer`

A pointer to a buffer that receives the authentication [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

### `ulSize`

The size, in bytes, of the buffer that the **pBuffer** member points to.

### `ulType`

The data type of the buffer that the **pBuffer** member points to.

| Value | Meaning |
| --- | --- |
| 1 | PCCERT_CONTEXT |

## Remarks

This structure is included as a member in the [DAV_CALLBACK_CRED](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_cred) structure.

The [DavFreeCredCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback_freecred) callback function should free only the buffer that the **pBuffer** member points to, not the entire structure.

## See also

[DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp)

[DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback)