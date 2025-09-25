# GetServerForPMP function

## Description

Gets a COM server that has been registered for Protected Media Process (PMP) usage with previous call to [RegisterServerForPMP](https://learn.microsoft.com/windows/desktop/api/comppkgsup/nf-comppkgsup-registerserverforpmp).

## Parameters

### `serverClassId`

The CLSID of the server to be retrieved.

### `unknown` [out]

Receives a pointer to the requested COM server interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.