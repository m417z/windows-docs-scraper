# IAzAuthorizationStore::Delete

## Description

The **Delete** method deletes the policy store currently in use by the [AzAuthorizationStore](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazauthorizationstore) object.

## Parameters

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

When the **Delete** method is called, the [AzAuthorizationStore](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazauthorizationstore) object returns to an uninitialized state. The [Initialize](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-initialize) method can then be called to reinitialize the object.

>[!IMPORTANT]
>All objects opened by clients on the policy store (for example, [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) objects created using [CreateApplication](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-createapplication)) must be released before you call the **Delete** method. If the **Delete** method is called on an [AzAuthorizationStore](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazauthorizationstore) object whose current policy store contains child objects, **HRESULT_FROM_WIN32(ERROR_SERVER_HAS_OPEN_HANDLES)** is returned.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)

[AzAuthorizationStore](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazauthorizationstore)

[CreateApplication](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-createapplication)