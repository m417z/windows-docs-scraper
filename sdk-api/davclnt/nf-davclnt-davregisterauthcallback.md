# DavRegisterAuthCallback function

## Description

Registers an application-defined callback function that the WebDAV client can use to prompt the user for credentials.

## Parameters

### `CallBack` [in]

A pointer to a function of type [PFNDAVAUTHCALLBACK](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback).

### `Version` [in]

This parameter is reserved for future use.

## Return value

If the function succeeds, the return value is an opaque handle. Note that **OPAQUE_HANDLE** is defined to be a **DWORD** value.

## Remarks

The WebDAV client uses the callback function when it is unable to connect to a remote resource using default credentials.

To unregister the callback function, use the [DavUnregisterAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davunregisterauthcallback) function, passing the returned opaque handle in the *hCallback* parameter.

## See also

[DavUnregisterAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davunregisterauthcallback)