# ConnectToConnectionPoint function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Establishes or terminates a connection between a client's sink and a connection point container.

## Parameters

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object to be connected to the connection point container. If you set *fConnect* to **FALSE** to indicate that you are disconnecting the object, this parameter is ignored and can be set to **NULL**.

### `riidEvent` [in]

Type: **REFIID**

The IID of the interface on the connection point container whose connection point object is being requested.

### `fConnect`

Type: **BOOL**

**TRUE** if a connection is being established; **FALSE** if a connection is being broken.

### `punkTarget` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the connection point container's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `pdwCookie` [out]

Type: **DWORD***

A connection token. If you set *fConnect* to **TRUE** to make a new connection, this parameter receives a token that uniquely identifies the connection. If you set *fConnect* to **FALSE** to break a connection, this parameter must point to the token that you received when you called **ConnectToConnectionPoint** to establish the connection.

### `ppcpOut` [out, optional]

Type: **[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)****

A pointer to the connection point container's [IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface, if the operation was successful. The calling application must release this pointer when it is no longer needed. If the request is unsuccessful, the pointer receives **NULL**. This parameter is optional and can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.