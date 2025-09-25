# DAV_CALLBACK_CRED structure

## Description

Stores user credential information that was retrieved by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## Members

### `AuthBlob`

If the **bAuthBlobValid** member is **TRUE**, this member is a [DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob) structure that contains the user credential information.

### `UNPBlob`

If the **bAuthBlobValid** member is **FALSE**, this member is a [DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp) structure that contains the user credential information.

### `bAuthBlobValid`

**TRUE** if the credential information is stored in the **AuthBlob** member, and the **UNPBlob** member should be ignored. **FALSE** if it is stored in the **UNPBlob** member, and the **AuthBlob** member should be ignored.

### `bSave`

**TRUE** if the credential information was written to the [credential manager](https://learn.microsoft.com/windows/desktop/SecAuthN/credential-manager), or **FALSE** otherwise.

## Remarks

This structure is used by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## See also

[DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob)

[DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp)

[DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback)

[DavFreeCredCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback_freecred)