# IExplorerCommandProvider::GetCommands

## Description

Gets a specified Explorer command enumerator instance.

## Parameters

### `punkSite`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an interface used to set a site.

### `riid`

Type: **REFIID**

A reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in riid. This will typically be [IEnumExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumexplorercommand).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.