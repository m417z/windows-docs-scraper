# RegisterServerForPMP function

## Description

Registers a COM Server CLSID and a class factory for Protected Media Process (PMP) usage.

## Parameters

### `serverClassId`

The CLSID of the COM server to be registered.

### `classFactory`

The class factory to be registered.

### `token` [out]

Receives a pointer to a registration token that can be used to unregister the server with [UnregisterServerForPMP](https://learn.microsoft.com/windows/desktop/api/comppkgsup/nf-comppkgsup-unregisterserverforpmp).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.