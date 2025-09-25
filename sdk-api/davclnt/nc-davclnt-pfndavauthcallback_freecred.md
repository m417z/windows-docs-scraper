# PFNDAVAUTHCALLBACK_FREECRED callback function

## Description

The WebDAV client calls the application-defined *DavFreeCredCallback* callback function to free the credential information that was retrieved by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

The *PFNDAVAUTHCALLBACK_FREECRED* type defines a pointer to this callback function. *DavFreeCredCallback* is a placeholder for the application-defined function name.

## Parameters

### `pbuffer` [in]

A pointer to the [DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp) or [DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob) structure that was used in the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The *DavFreeCredCallback* callback function must be registered by calling the [DavRegisterAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davregisterauthcallback) function.

This callback function should free only the buffer that the **pBuffer** member of the [DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp) or [DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob) structure points to, not the entire structure.

## See also

[DAV_CALLBACK_CRED](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_cred)

[DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback)