# INetFwProducts::Item

## Description

The **Item** method returns the product with the specified index if it is in the collection.

## Parameters

### `index` [in]

Index of the product to retrieve.

### `product` [out, retval]

Reference to the returned [INetFwProduct](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproduct) object.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The requested item does not exist. |

## See also

[INetFwProduct](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproduct)

[INetFwProducts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproducts)