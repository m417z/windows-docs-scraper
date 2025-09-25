# IEnumExplorerCommand::Next

## Description

Retrieves a specified number of elements that directly follow the current element.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of elements to fetch.

### `pUICommand` [out]

Type: **[IExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommand)****

Address of an [IExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommand) interface pointer array of *celt* elements that, when this method returns, is an array of pointers to the retrieved elements.

### `pceltFetched` [out, optional]

Type: **ULONG***

When this method returns, contains a pointer to the number of elements actually retrieved. This pointer can be **NULL** if this information is not needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.