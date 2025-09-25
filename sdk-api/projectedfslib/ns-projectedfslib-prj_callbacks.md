# PRJ_CALLBACKS structure

## Description

A set of callback routines to where the provider stores its implementation of the callback.

## Members

### `StartDirectoryEnumerationCallback`

A pointer to the StartDirectoryEnumerationCallback.

### `EndDirectoryEnumerationCallback`

A pointer to the EndDirectoryEnumerationCallback.

### `GetDirectoryEnumerationCallback`

A pointer to the GetDirectoryEnumerationCallback.

### `GetPlaceholderInfoCallback`

A pointer to the GetPlaceholderInformationCallback.

### `GetFileDataCallback`

A pointer to the GetFileDataCallback.

### `QueryFileNameCallback`

A pointer to the QueryFileNameCallback.

### `NotificationCallback`

A pointer to the NotifyOperationCallback.

### `CancelCommandCallback`

A pointer to the CancelCommandCallback.

## Remarks

The provider must supply implementations for StartDirectoryEnumerationCallback, EndDirectoryEnumerationCallback, GetDirectoryEnumerationCallback, GetPlaceholderInformationCallback, and GetFileDataCallback.

The QueryFileNameCallback, NotifyOperationCallback, and CancelCommandCallback callbacks are optional.

* If the provider does not supply an implementation of QueryFileNameCallback, ProjFS will invoke the directory enumeration callbacks to determine the existence of a file path in the provider's store.
* If the provider does not supply an implementation of NotifyOperationCallback, it will not get any notifications from ProjFS.
* If the provider does not supply an implementation of CancelCommandCallback, none of the other callbacks will be cancellable. The provider will process all callbacks synchronously.