# IEnumAssocHandlers::Next

## Description

Retrieves a specified number of elements.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements to retrieve.

### `rgelt` [out]

Type: **[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler)****

When this method returns, contains the address of an array of [IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler) pointers. Each **IAssocHandler** represents a single handler.

### `pceltFetched` [out]

Type: **ULONG***

When this method returns, contains a pointer to the number of elements retrieved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.