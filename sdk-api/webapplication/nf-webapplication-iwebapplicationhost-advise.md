# IWebApplicationHost::Advise

## Description

Establishes a connection to allow a client to receive events.

## Parameters

### `interfaceId` [in]

Type: **REFIID**

The identifier of the event interface.

### `callback` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The caller's event interface.

### `cookie` [out]

Type: **DWORD***

A token that uniquely identifies this connection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationhost)

[IWebApplicationHost::Unadvise](https://learn.microsoft.com/previous-versions/windows/desktop/debug_wwahost/iwebapplicationhost-unadvise)