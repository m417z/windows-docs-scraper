# IExplorerCommandProvider::GetCommand

## Description

Gets a specified Explorer command instance.

## Parameters

### `rguidCommandId`

Type: **REFGUID**

A reference to a command ID as a **GUID**. Used to obtain a command definition.

### `riid`

Type: **REFIID**

A reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in riid. This will typically be [IExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommand).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.