# SslGetServerIdentity function

## Description

The **SslGetServerIdentity** function gets the identity of the server. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Schannel.dll.

## Parameters

### `ClientHello` [in]

The message from the client.

### `ClientHelloSize` [in]

The size of the client message.

### `ServerIdentity` [out]

The pointer inside the message where the server name starts.

### `ServerIdentitySize` [out]

The length of the server name.

### `Flags` [in]

This parameter is reserved and must be zero.

## Return value

The status of the call to the function.

| Return code | Description |
| --- | --- |
| **SEC_E_OK** | The function was successful. |
| **SEC_E_INVALID_PARAMETER** | One of the parameters *ClientHello*, *ServerIdentity*, or *ServerIdentitySize* is **NULL**. |
| **SEC_E_INCOMPLETE_MESSAGE** | The *ServerIdentitySize* parameter is smaller than the *ClientHelloSize* parameter. |