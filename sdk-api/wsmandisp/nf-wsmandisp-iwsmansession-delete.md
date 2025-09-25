# IWSManSession::Delete

## Description

Deletes the resource specified in the resource URI.

## Parameters

### `resourceUri` [in]

The URI of the resource to be deleted. You can also use an [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object to specify the resource.

### `flags` [in, optional]

Reserved for future use. Must be set to 0.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Delete](https://learn.microsoft.com/windows/desktop/WinRM/session-delete)