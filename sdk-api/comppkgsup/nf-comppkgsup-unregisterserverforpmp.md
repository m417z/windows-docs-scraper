# UnregisterServerForPMP function

## Description

Registers a COM Server CLSID and a class factory that were previously registered for Protected Media Process (PMP) usage.

## Parameters

### `token`

The registration token obtained from a previous call to [RegisterServerForPMP](https://learn.microsoft.com/windows/desktop/api/comppkgsup/nf-comppkgsup-registerserverforpmp).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.